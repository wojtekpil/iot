/*
 * Device.h
 *
 *  Created on: 8 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_DEVICE_DEVICE_H_
#define LIB_IOT_MODULES_DEVICE_DEVICE_H_
#include <string>
#include <map>
#include <vector>
#include <memory>

#include "../../Model.h"

namespace iot {

/**
 * Abstract device class, simplifies communucation between Model and Link
 */
class Device: public Model {
public:
	typedef std::map<std::string, std::string> tDeviceData;
	Device();
	virtual void update(tDeviceData devData);
	virtual void afterUpdate(std::shared_ptr<std::vector<std::string>>)=0;
	virtual ~Device();
protected:
	tDeviceData _fields;
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_DEVICE_DEVICE_H_ */
