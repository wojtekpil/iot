/*
 * Core.cpp
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#include "Core.h"
#include <iostream>

#include "modules/Logger/LoggerFactory.h"

namespace iot {

Core::Core() {
	// TODO Auto-generated constructor stub

}

Core::~Core() {
	// TODO Auto-generated destructor stub
}

void Core::run() {
	LoggerFactory lf;
	std::shared_ptr<Logger> logger = lf.createProduct();
	logger->debug("Core of IoT is starting...");
}

} /* namespace iot */


