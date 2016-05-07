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
	// TODO Auto-generated constructor stub
	this->_uniqueName = "ConsoleLogger";
}

void ConsoleLogger::debug(std::string msg) {
	showTime();
	std::cout << "DEBUG: " << msg << std::endl;
}

void ConsoleLogger::warn(std::string msg) {
	showTime();
	std::cout << "WARN: " << msg << std::endl;
}

void ConsoleLogger::error(std::string msg) {
	showTime();
	std::cout << "ERROR: " << msg << std::endl;
}

void ConsoleLogger::showTime() {
	time_t tim;
	struct tm * data;
	char act_time[80];

	time(&tim);
	data = localtime(&tim);
	strftime(act_time, 80, "[%H:%M:%S] ", data);
	std::cout<<act_time;
}

ConsoleLogger::~ConsoleLogger() {
	// TODO Auto-generated destructor stub
}

} /* namespace iot */