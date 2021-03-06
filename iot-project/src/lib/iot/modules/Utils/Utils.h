/*
 * Utils.h
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_UTILS_UTILS_H_
#define LIB_IOT_MODULES_UTILS_UTILS_H_

namespace iot {

/**
 * Utils class containing some static method that are common in application
 */
class Utils {
public:
	Utils();
	void onStartup();
	virtual ~Utils();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_UTILS_UTILS_H_ */
