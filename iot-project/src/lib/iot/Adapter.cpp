/*
 * Adapter.cpp
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#include "Adapter.h"
#include "modules/Logger/LoggerFactory.h"

namespace iot {

Adapter::Adapter() {

}
/**
 * Shorthand for LoggerFactory
 * @return Logger
 */
std::shared_ptr<Logger> Adapter::log() {
	LoggerFactory lf;
	return lf.createProduct();
}



Adapter::~Adapter() {
}

} /* namespace iot */
