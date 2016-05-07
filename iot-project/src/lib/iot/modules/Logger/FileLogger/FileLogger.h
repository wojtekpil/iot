/*
 * FileLogger.h
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_MODULES_LOGGER_FILELOGGER_FILELOGGER_H_
#define LIB_MODULES_LOGGER_FILELOGGER_FILELOGGER_H_

#include "../Logger.h"

namespace iot {

class FileLogger: public Logger {
public:
	FileLogger();
	bool open(std::string fileName);
	bool close();
	virtual void debug(std::string msg);
	virtual void warn(std::string msg);
	virtual void error(std::string msg);
	virtual ~FileLogger();
};

} /* namespace iot */

#endif /* LIB_MODULES_LOGGER_FILELOGGER_FILELOGGER_H_ */
