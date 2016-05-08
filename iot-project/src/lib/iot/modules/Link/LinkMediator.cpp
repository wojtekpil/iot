/*
 * LinkMediator.cpp
 *
 *  Created on: 8 maj 2016
 *      Author: wojtek
 */

#include "LinkMediator.h"

namespace iot {

LinkMediator::LinkMediator() {

}
/**
 * Register Link type in LinkMediator for communication between Device Model and Link
 * @param link
 * @return
 */
bool LinkMediator::registerLink(std::shared_ptr<Link> link) {
	std::lock_guard<std::mutex> guard(this->_linkMutex);
	this->_links[link->getName()] = link;
	return true;
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
	ld.link = this->_links.begin()->second; //Temporary!!!
	this->_devices.push_back(ld);
	return true;
}
/**
 * Removes link type from LinkMediator, doesnt work if Link is already in use
 * @param link
 * @return
 */
bool LinkMediator::unregisterLink(std::shared_ptr<Link> link) {
	std::lock_guard<std::mutex> guard(this->_linkMutex);
	std::map<std::string, std::shared_ptr<Link>>::iterator iter =
			this->_links.find(link->getName());
	if (iter != this->_links.end()){
		this->_links.erase(iter);
		return true;
	}
	return false;
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

LinkMediator::~LinkMediator() {
}

} /* namespace iot */
