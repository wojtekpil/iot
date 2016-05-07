/*
 * TemperatureCreator.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef APP_MODELS_TEMPERATURE_TEMPERATURECREATOR_H_
#define APP_MODELS_TEMPERATURE_TEMPERATURECREATOR_H_

#include <memory>

#include "Temperature.h"
#include "../../../lib/iot/ModelCreator.h"

namespace app {
namespace model{

class TemperatureCreator: public iot::ModelCreator {
public:
	TemperatureCreator() {}
	std::shared_ptr<iot::Model> produce() {
		return std::make_shared<app::model::Temperature>();
	};
	virtual ~TemperatureCreator() {}
};

} /* namespace model */
} /* namespace iot */


#endif /* APP_MODELS_TEMPERATURE_TEMPERATURECREATOR_H_ */
