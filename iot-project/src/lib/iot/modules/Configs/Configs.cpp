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

bool Configs::set(std::string field, std::string value) {
	this->_fields[field] = value;
}

std::string Configs::get(std::string field) {
	return this->_fields[field];
}

Configs& Configs::getInstance() {
	//singielton, utworz tylko jeden obiekt configs w calej aplikacji
	static Configs instance;
	return instance;
}

Configs::~Configs() {
}

} /* namespace iot */
