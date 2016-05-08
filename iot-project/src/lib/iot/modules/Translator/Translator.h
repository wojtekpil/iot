/*
 * Translator.h
 *
 *  Created on: 8 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_TRANSLATOR_TRANSLATOR_H_
#define LIB_IOT_MODULES_TRANSLATOR_TRANSLATOR_H_

#include "../Device/Device.h"

namespace iot {

/**
 * Class translating messages between device and Model of that Device
 */
class Translator {
public:
	Translator();
	virtual Device::tDeviceData toSystem(std::string fromDev)=0;
	virtual std::string toDevice(Device::tDeviceData fromSys)=0;
	virtual ~Translator();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_TRANSLATOR_TRANSLATOR_H_ */
