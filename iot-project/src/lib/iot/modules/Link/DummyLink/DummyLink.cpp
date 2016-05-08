/*
 * DummyLink.cpp
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#include "DummyLink.h"
#include "../../Logger/LoggerFactory.h"

namespace iot {

DummyLink::DummyLink() {
	this->_uniqueName = "DummyLink";
}

std::shared_ptr<Logger> DummyLink::log() {
	LoggerFactory lf;
	return lf.createProduct();
}

bool DummyLink::connect(std::string conf) {
	this->log()->debug("DummyLink connecting...");
	return true;
}

bool DummyLink::disconnect() {
	this->log()->debug("DummyLink disconnecting...");
	return true;
}

bool DummyLink::send(std::shared_ptr<Spacket> packet) {
	this->log()->debug("DummyLink Sending packet: " + packet->message);
	return true;
}

bool DummyLink::read(std::shared_ptr<Spacket> packet) {
	static uint32_t time_here = 0;
	packet->time = time_here;
	packet->message = "DummyLink msg";
	time_here++;
	return true;
}

DummyLink::~DummyLink() {
}

} /* namespace iot */
