/*
 * Link.cpp
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#include "Link.h"

namespace iot {

Link::Link() {

}

Link::~Link() {
}

const std::string& Link::getName() const {
	return this->_uniqueName;
}

} /* namespace iot */
