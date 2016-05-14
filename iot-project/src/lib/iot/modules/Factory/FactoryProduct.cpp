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

void FactoryProduct::setUniqueName(std::string name) {
	this->_uniqueName = name;
}


FactoryProduct::~FactoryProduct() {
}

} /* namespace iot */

