/*
 * Device.cpp
 *
 *  Created on: 8 maj 2016
 *      Author: wojtek
 */

#include "Device.h"

namespace iot {

Device::Device() {
}

/**
 * Update data in Device Model
 * @param devData
 */
void Device::update(tDeviceData devData) {
	//update exitising fileds
	for (const auto& kv : devData) {
		this->_fields[kv.first] = kv.second;
	}
	//run after update for tuning
	afterUpdate();
}

Device::~Device() {
}

} /* namespace iot */
