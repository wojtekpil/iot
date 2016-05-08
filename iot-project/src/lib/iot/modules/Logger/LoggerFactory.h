/*
 * LoggerFactory.h
 * Abstract Factory for Loggers
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_LOGGER_LOGGERFACTORY_H_
#define LIB_IOT_MODULES_LOGGER_LOGGERFACTORY_H_

#include "../Factory/Factory.h"
#include "Logger.h"
#include <memory>
#include <string>
#include <map>
namespace iot {

/**
 * Factory of configured Logger
 */
class LoggerFactory: public Factory {
private:
	std::map<std::string, std::shared_ptr<Logger> > _loggers;
	void registerCreator(std::shared_ptr<Logger> factoryProduct);
public:
	LoggerFactory();
	virtual std::shared_ptr<Logger> createProduct();
	virtual ~LoggerFactory();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_LOGGER_LOGGERFACTORY_H_ */
