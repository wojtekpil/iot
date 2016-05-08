/*
 * Model.cpp
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#include "Model.h"
#include "modules/Logger/LoggerFactory.h"

namespace iot {

Model::Model() {
}

Model::~Model() {
}
/**
 * Shorthand for LoggerFactory
 * @return Logger ptr
 */
std::shared_ptr<Logger> Model::log() {
	LoggerFactory lf;
	return lf.createProduct();
}

} /* namespace iot */


