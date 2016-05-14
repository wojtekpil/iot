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
	auto updated = std::make_shared<std::vector<std::string>>();
	//update exitising fileds
	for (const auto& kv : devData) {
		this->_fields[kv.first] = kv.second;
		updated->push_back(kv.first);
	}
	//run after update for tuning
	if(updated->size()>0)
		afterUpdate(updated);
}

Device::~Device() {
}

} /* namespace iot */
