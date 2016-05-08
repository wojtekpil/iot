/*
 * Device.cpp
 *
 *  Created on: 8 maj 2016
 *      Author: wojtek
 */

#include "Device.h"

namespace iot {

Device::Device() {
	// TODO Auto-generated constructor stub

}

void Device::update(tDeviceData devData) {
	//update exitising fileds
	for (const auto& kv : devData) {
		this->_fields[kv.first] = kv.second;
	}
	//run after update for tuning
	afterUpdate();
}

Device::~Device() {
	// TODO Auto-generated destructor stub
}

} /* namespace iot */
