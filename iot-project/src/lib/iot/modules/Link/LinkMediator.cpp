/*
 * LinkMediator.cpp
 *
 *  Created on: 8 maj 2016
 *      Author: wojtek
 */

#include "LinkMediator.h"
#include "LinkFactory.h"
#include "../Logger/LoggerFactory.h"
#include "../Exception/Exception.h"
#include <algorithm>
#include <chrono>
#include <iostream>

namespace iot {

LinkMediator::LinkMediator() {
}
/**
 * Register Link type in LinkMediator for communication between Device Model and Link
 * @param link
 * @return
 */
bool LinkMediator::registerLink(std::string linkName) {
	std::lock_guard<std::mutex> guard(this->_linkMutex);
	//check if linkName is already in list
	if ( std::find(this->_links.begin(), this->_links.end(), linkName) == this->_links.end() ){
		this->_links.push_back(linkName);
		//this->_linkThreads.push_back(std::thread(LinkMediator::linkReader,this, linkName));
		return true;
	}
	return false;
}
/**
 * Register connection between Device Model, Link using given Translator (from link to model)
 * @param config - describe link connection
 * @param dev - device model
 * @param trans - translator from link to model data
 * @return
 */
bool LinkMediator::registerDevice( Sdevice config,
		std::shared_ptr<Device> dev, std::shared_ptr<Translator> trans) {
	std::lock_guard<std::mutex> guard(this->_linkMutex);
	// FIXME translate Link from config
	SlinkDevice ld;
	ld.conf = &config;
	ld.dev = dev;
	ld.trans = trans;
	ld.linkName = this->_links.at(0); //Temporary!!!
	this->_devices.push_back(ld);
	return true;
}
/**
 * Removes link type from LinkMediator, doesnt work if Link is already in use
 * @param link
 * @return
 */
bool LinkMediator::unregisterLink(std::string linkName) {
	std::lock_guard<std::mutex> guard(this->_linkMutex);
	this->_links.erase(std::remove(this->_links.begin(), this->_links.end(), linkName), this->_links.end());
	return true;
}
/**
 * Removes connection of Device Model and Link
 * @param config - describe link connection
 * @param dev - device model
 * @return
 */
bool LinkMediator::unregisterDevice(Sdevice config,
		std::shared_ptr<Device> dev) {
	std::lock_guard<std::mutex> guard(this->_linkMutex);
	// FIXME unregister Device
	return true;
}

void LinkMediator::notify(std::shared_ptr<Spacket> packet) {
	std::lock_guard<std::mutex> guard(this->_linkMutex);
	uint32_t found_devices = 0;
	for (auto &dev : this->_devices) // access by reference to avoid copying
	{
		if (dev.conf->addr == packet->dev.addr) {
			dev.dev->update(dev.trans->toSystem(packet->message));
			found_devices++;
		}
	}
	// TODO handle unregistered devices
	if(found_devices == 0) {
		LoggerFactory lf;
		lf.createProduct()->warn("LinkMediator: Device with ID: " + std::to_string(packet->dev.addr)+ "not registered");
	}
}

/**
 * Reading Link threads starts here
 * @param mediator pointer to mediator object
 * @param linkName link to read
 */
void LinkMediator::linkReader(std::string linkName) {

	try {
		LoggerFactory lf;
		lf.createProduct()->debug("Thread of Link: "+ linkName+" started");
		auto linkf = new LinkFactory();
		auto link = linkf->createProduct(linkName);
		this->_linkInstances[linkName] = link;
		link->connect("1234", this);


	} catch (Exception& e) {
		LoggerFactory lf;
		lf.createProduct()->error(e.getMsg());
	}
}


void LinkMediator::shutdown() {


	// FIXME remove test sleep
	//std::this_thread::sleep_for(std::chrono::seconds(20));
	int test;
	std::cin>>test;
	LoggerFactory lf;
	lf.createProduct()->debug("Closing  Links");
	for(const auto& link: this->_linkInstances) {
		link.second->disconnect();
	}
}

/**
 * Send packet to device
 * @param packet
 */
void LinkMediator::send(std::shared_ptr<Spacket> packet) {
	std::lock_guard<std::mutex> guard(this->_linkMutex);
	//FIXME real network conf
	auto link = this->_linkInstances.find(packet->dev.network_conf);
	if ( link != this->_linkInstances.end() ) {
		link->second->send(packet);
	} else {
		LoggerFactory lf;
		lf.createProduct()->warn("LinkMediator: Link: " + packet->dev.network_conf+ " not registered");
	}

}

void LinkMediator::start() {
	for(const auto& link: this->_links) {
		this->linkReader(link);
	}
}

LinkMediator::~LinkMediator() {
	//this->shutdown();
}

} /* namespace iot */
