/*
 * FactoryProduct.cpp
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#include "FactoryProduct.h"

namespace iot {

FactoryProduct::FactoryProduct() {
}

/**
 * Get unique name of factory product
 * @return name
 */
std::string FactoryProduct::getUniqueName() {
	return this->_uniqueName;
}

FactoryProduct::~FactoryProduct() {
}

} /* namespace iot */


