/*
 * ConsoleLogger.h
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_LOGGER_CONSOLELOGGER_CONSOLELOGGER_H_
#define LIB_IOT_MODULES_LOGGER_CONSOLELOGGER_CONSOLELOGGER_H_

#include "../Logger.h"
#include <mutex>

namespace iot {

class ConsoleLogger: public Logger {
private:
	void showTime();
	std::mutex _loggerMutex;
public:
	ConsoleLogger();
	virtual void debug(std::string msg);
	virtual void warn(std::string msg);
	virtual void error(std::string msg);
	virtual ~ConsoleLogger();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_LOGGER_CONSOLELOGGER_CONSOLELOGGER_H_ */
