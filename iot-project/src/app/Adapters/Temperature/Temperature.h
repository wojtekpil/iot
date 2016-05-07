/*
 * Temperature.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef APP_ADAPTERS_TEMPERATURE_TEMPERATURE_H_
#define APP_ADAPTERS_TEMPERATURE_TEMPERATURE_H_

#include "../../../lib/iot/Adapter.h"

namespace app {
namespace adapter {

class Temperature: public iot::Adapter {
public:
	Temperature();
	virtual void init(std::shared_ptr<Adapter> adapter);
	virtual void update(std::string observableName);
	virtual ~Temperature();
};

} /* namespace adapter */
} /* namespace app */

#endif /* APP_ADAPTERS_TEMPERATURE_TEMPERATURE_H_ */
