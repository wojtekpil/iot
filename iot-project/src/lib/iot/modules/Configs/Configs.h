/*
 * Configs.h
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_CONFIGS_CONFIGS_H_
#define LIB_IOT_MODULES_CONFIGS_CONFIGS_H_

#include <string>
#include <map>

namespace iot {

class Configs {
private:
	std::map<std::string, std::string> _fields;
	Configs();
	Configs(const Configs &);
	Configs& operator=(const Configs&);
	~Configs();
public:
	bool set(std::string field, std::string value);
	std::string get(std::string field);
	static Configs& getInstance();

};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_CONFIGS_CONFIGS_H_ */
