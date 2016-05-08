/*
 * Exception.h
 * Main Exception Class in IoT
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_EXCEPTION_EXCEPTION_H_
#define LIB_IOT_MODULES_EXCEPTION_EXCEPTION_H_

#include <string>

namespace iot {

/**
 * Main Exception class
 */
class Exception {
protected:
	std::string _ex_msg;
public:
	Exception(std::string msg);
	void msg(std::string msg);
	std::string getMsg();
	virtual ~Exception();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_EXCEPTION_EXCEPTION_H_ */
