/*
 * LoggerFactory.cpp
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */


#include "LoggerFactory.h"
#include "../Configs/Configs.h"
#include "../Exception/Exception.h"

#include "ConsoleLogger/ConsoleLogger.h"
#include "FileLogger/FileLogger.h"


namespace iot {

/**
 * Consturctor of LoggerFactory, put your loggers registration here
 */
LoggerFactory::LoggerFactory() {
	//add your loggers here
	this->registerCreator(std::shared_ptr<Logger>(new ConsoleLogger()));
	this->registerCreator(std::shared_ptr<Logger>(new FileLogger()));
}
/**
 * Generates logger using config value
 * @return Logger
 */
std::shared_ptr<Logger> LoggerFactory::createProduct() {
	std::string loggerName = Configs::getInstance().get("Logger");
	//if config is set and logger with given name exists
	if (!loggerName.empty() && this->_loggers.find(loggerName) != this->_loggers.end()) {
		return this->_loggers[loggerName];
	} else {
		throw Exception("No valid Logger is set! Please configure it in your bootstrap file");
	}
}

/**
 * Register acessible loggers
 * @param factoryProduct - Logger to register
 */
void LoggerFactory::registerCreator(std::shared_ptr<Logger> factoryProduct) {
	//register logger to avaible list
	this->_loggers[(factoryProduct->getUniqueName())] = factoryProduct;
}




LoggerFactory::~LoggerFactory() {
	// clear map of loggers
	std::map<std::string, std::shared_ptr<Logger>>::iterator itr = this->_loggers.begin();
	while (itr != this->_loggers.end()) {
		itr = this->_loggers.erase(itr);
	}
}

} /* namespace iot */
