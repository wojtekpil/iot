/*
 * ConsoleLogger.cpp
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#include "ConsoleLogger.h"
#include <iostream>
#include <ctime>

namespace iot {

ConsoleLogger::ConsoleLogger() {
	this->_uniqueName = "ConsoleLogger";
}

void ConsoleLogger::debug(std::string msg) {
	this->_loggerMutex.lock();
	showTime();
	std::cout << "DEBUG: " << msg << std::endl;
	this->_loggerMutex.unlock();
}

void ConsoleLogger::warn(std::string msg) {
	this->_loggerMutex.lock();
	showTime();
	std::cout << "WARN: " << msg << std::endl;
	this->_loggerMutex.unlock();
}

void ConsoleLogger::error(std::string msg) {
	this->_loggerMutex.lock();
	showTime();
	std::cout << "ERROR: " << msg << std::endl;
	this->_loggerMutex.unlock();
}

void ConsoleLogger::showTime() {
	time_t tim;
	struct tm * data;
	char act_time[81];

	time(&tim);
	data = localtime(&tim);
	strftime(act_time, 80, "[%H:%M:%S] ", data);
	std::cout<<act_time;
}

ConsoleLogger::~ConsoleLogger() {
}

} /* namespace iot */
