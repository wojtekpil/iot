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
	this->notify("");
}

void Temperature::afterUpdate(std::shared_ptr<std::vector<std::string>> updated) {

	this->log()->debug("app::model::Temperature: Some Updates were here");
	for(const auto& field: (*updated)) {
		if(field == "temp") {
			this->temperatureHandler(this->_fields[field]);
		}
		this->log()->debug("app::model::Temperature: "+field+"="+this->_fields[field]);
	}
}

void Temperature::temperatureHandler(std::string actTemp) {
	static uint32_t last_temp = 0;
	uint32_t temp = 0;
	try {
		temp = std::stoul(actTemp);
	} catch(std::invalid_argument& ex) {
		this->log()->error("app::model::Temperature: wrong temperature: " + actTemp);
	}
	std::string result = "no_change";
	if(temp>last_temp) {
		result = "rising";
	} else if(temp<last_temp) {
		result = "falling";
	}
	last_temp = temp;
	this->notify(result);
}

std::string Temperature::getTemperature() {
	return this->_fields.at("temp");
}


Temperature::~Temperature() {
}

} /* namespace model */
} /* namespace app */


