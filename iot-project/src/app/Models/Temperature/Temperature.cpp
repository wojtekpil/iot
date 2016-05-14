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

void Temperature::afterUpdate(std::shared_ptr<std::vector<std::string>> updated) {
	this->log()->debug("Some Updates were here");
	for(const auto& field: (*updated)) {
		this->log()->debug("app::model::Temperature: "+field+"="+this->_fields[field]);
	}
}

Temperature::~Temperature() {
}

} /* namespace model */
} /* namespace app */


