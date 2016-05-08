/*
 * FileLogger.cpp
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#include "FileLogger.h"

namespace iot {

FileLogger::FileLogger() {
	//open log file
	this->_uniqueName = "FileLogger";
	open("logs/log.txt");

}

bool FileLogger::open(std::string fileName) {
	// TODO open logging file
	return true;
}

bool FileLogger::close() {
	// TODO close logging file
	return true;
}

void FileLogger::debug(std::string msg) {

}

void FileLogger::warn(std::string msg) {

}

void FileLogger::error(std::string msg) {

}


FileLogger::~FileLogger() {
	close();
}

} /* namespace iot */
