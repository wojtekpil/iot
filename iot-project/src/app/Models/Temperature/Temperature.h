/*
 * Temperature.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef APP_MODELS_TEMPERATURE_TEMPERATURE_H_
#define APP_MODELS_TEMPERATURE_TEMPERATURE_H_

#include "../../../lib/iot/modules/Device/Device.h"

namespace app {
namespace model {

class Temperature : public iot::Device{
public:
	Temperature();
	void makeEvent();
	virtual void afterUpdate(std::shared_ptr<std::vector<std::string>>);
	virtual ~Temperature();
};

} /* namespace model */
} /* namespace app */

#endif /* APP_MODELS_TEMPERATURE_TEMPERATURE_H_ */
