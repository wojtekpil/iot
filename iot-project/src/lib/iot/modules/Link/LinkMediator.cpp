/*
 * LinkMediator.cpp
 *
 *  Created on: 8 maj 2016
 *      Author: wojtek
 */

#include "LinkMediator.h"
#include "../Logger/LoggerFactory.h"
#include <algorithm>
#include <chrono>
#include <iostream>

namespace iot {

LinkMediator::LinkMediator() {
	running = true;
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
		this->_linkThreads.push_back(std::thread(LinkMediator::linkReader,this, linkName));
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
bool LinkMediator::registerDevice(Link::Sdevice config,
		std::shared_ptr<Device> dev, std::shared_ptr<Translator> trans) {
	std::lock_guard<std::mutex> guard(this->_linkMutex);
	// FIXME translate Link from config
	SlinkDevice ld;
	ld.conf = config;
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
bool LinkMediator::unregisterDevice(Link::Sdevice config,
		std::shared_ptr<Device> dev) {
	std::lock_guard<std::mutex> guard(this->_linkMutex);
	// FIXME unregister Device
	return true;
}

void LinkMediator::notify() {
	std::lock_guard<std::mutex> guard(this->_linkMutex);
	// FIXME connect Link with Device in LinkMediator
}

/**
 * Reading Link threads starts here
 * @param mediator pointer to mediator object
 * @param linkName link to read
 */
void LinkMediator::linkReader(LinkMediator* mediator, std::string linkName) {
	LoggerFactory lf;
	lf.createProduct()->debug("Thread of Link: "+ linkName+" started");
	while(mediator->running.load()) {
		// TODO Creation and reading from Link objects
		std::this_thread::sleep_for(std::chrono::seconds(1));
		lf.createProduct()->debug("Thread of Link: "+ linkName+" executing");
	}
	lf.createProduct()->debug("Thread of Link: "+ linkName+" ending");
}


void LinkMediator::shutdown() {


	// FIXME remove test sleep
	std::this_thread::sleep_for(std::chrono::seconds(3));
	running = false;
	LoggerFactory lf;
	lf.createProduct()->debug("Joining threads of Link");
	//join all threads
	for(auto &t : this->_linkThreads){
	        t.join();
	}
}

LinkMediator::~LinkMediator() {
	//this->shutdown();
}

} /* namespace iot */
