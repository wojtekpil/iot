/*
 * Exception.cpp
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#include "Exception.h"

namespace iot {

Exception::Exception(std::string msg) {
	this->_ex_msg = msg;
}

void Exception::msg(std::string msg) {
	this->_ex_msg = msg;
}

std::string Exception::getMsg() {
	return this->_ex_msg;
}

Exception::~Exception() {
}

} /* namespace iot */
