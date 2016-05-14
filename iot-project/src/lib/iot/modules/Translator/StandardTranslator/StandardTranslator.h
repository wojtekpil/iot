/*
 * StandardTranslator.h
 *
 *  Created on: 14 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_TRANSLATOR_STANDARDTRANSLATOR_STANDARDTRANSLATOR_H_
#define LIB_IOT_MODULES_TRANSLATOR_STANDARDTRANSLATOR_STANDARDTRANSLATOR_H_

#include "../Translator.h"

#include <string>
#include <vector>

namespace iot {


class StandardTranslator: public Translator {
public:
	StandardTranslator();
	std::vector<std::string> split(std::string str, const std::string& delimiter);
	virtual Device::tDeviceData toSystem(std::string fromDev);
	virtual std::string toDevice(Device::tDeviceData fromSys);
	virtual ~StandardTranslator();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_TRANSLATOR_STANDARDTRANSLATOR_STANDARDTRANSLATOR_H_ */
