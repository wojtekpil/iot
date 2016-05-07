/*
 * Logger.h
 * Abstract class, for logging functionality
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_MODULES_LOGGER_LOGGER_H_
#define LIB_MODULES_LOGGER_LOGGER_H_

#include <string>
#include "../Factory/FactoryProduct.h"

namespace iot {

class Logger: public FactoryProduct {
public:
	Logger();
	virtual void debug(std::string)=0;
	virtual void warn(std::string)=0;
	virtual void error(std::string)=0;
	virtual ~Logger();
};

} /* namespace iot */

#endif /* LIB_MODULES_LOGGER_LOGGER_H_ */
