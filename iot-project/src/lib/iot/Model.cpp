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
	// TODO Auto-generated constructor stub

}

Model::~Model() {
	// TODO Auto-generated destructor stub
}

std::shared_ptr<Logger> Model::log() {
	LoggerFactory lf;
	return lf.createProduct();
}

} /* namespace iot */


