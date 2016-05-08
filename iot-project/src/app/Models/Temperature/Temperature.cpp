/*
 * Temperature.cpp
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#include "Temperature.h"

namespace app {
namespace model {

Temperature::Temperature() {
	this->_name = "app::model::Temperature";
}

void Temperature::makeEvent() {
	this->notify();
}

Temperature::~Temperature() {
}

} /* namespace model */
} /* namespace app */
