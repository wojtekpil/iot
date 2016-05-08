/*
 * Core.cpp
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#include "Core.h"
#include <iostream>

#include "modules/Logger/LoggerFactory.h"
#include "ModelFactory.h"

namespace iot {

Core::Core() {
}



/**
 * Ater this point configuration off aplication is completed,
 * framework is stating its internal functionality
 */
void Core::run() {
	LoggerFactory lf;
	std::shared_ptr<Logger> logger = lf.createProduct();
	logger->debug("Core of IoT is starting...");

	//closing
	this->shutdown();
}
/**
 * Closing application, some cleaning is needed
 */
void Core::shutdown() {
	LoggerFactory lf;
	std::shared_ptr<Logger> logger = lf.createProduct();
	logger->debug("Core of IoT is shutting down...");
	ModelFactory::destroyCreators();
}

Core::~Core() {
}

} /* namespace iot */


