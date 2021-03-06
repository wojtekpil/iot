/*
 * Configs.cpp
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#include "Configs.h"

namespace iot {

Configs::Configs() {
}
/**
 * Set config value
 * @param field
 * @param value
 * @return
 */
bool Configs::set(std::string field, std::string value) {
	this->_configMutex.lock();
	this->_fields[field] = value;
	this->_configMutex.unlock();
	return true;
}

/**
 * Read config value
 * @param field
 * @return value of field
 */
std::string Configs::get(std::string field) {
	std::lock_guard<std::mutex> guard(this->_configMutex);
	return this->_fields[field];
}

/**
 *
 * @return instance of Configs
 */
Configs& Configs::getInstance() {
	//singielton, utworz tylko jeden obiekt configs w calej aplikacji
	static Configs instance;
	return instance;
}

Configs::~Configs() {
}

} /* namespace iot */
