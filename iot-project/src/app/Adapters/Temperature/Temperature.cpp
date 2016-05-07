/*
 * Temperature.cpp
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#include "Temperature.h"
#include "../../Models/Temperature/Temperature.h"

namespace app {
namespace adapter {

Temperature::Temperature() {
	// TODO Auto-generated constructor stub

}

void Temperature::init(std::shared_ptr<Adapter> adapter) {
	auto temp = std::make_shared<app::model::Temperature>();
	temp->atach(adapter);

	temp->makeEvent();
}

void Temperature::update(std::string observableName) {
	this->log()->debug("Event from: " + observableName);
}

Temperature::~Temperature() {
	// TODO Auto-generated destructor stub
}

} /* namespace adapter */
} /* namespace app */
