/*
 * Temperature.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef APP_ADAPTERS_TEMPERATURE_TEMPERATURE_H_
#define APP_ADAPTERS_TEMPERATURE_TEMPERATURE_H_

#include "../../../lib/iot/Adapter.h"
#include "../../../lib/iot/modules/Link/LinkMediator.h"

namespace app {
namespace adapter {

class Temperature: public iot::Adapter {
private:
	std::shared_ptr<iot::LinkMediator> _mediator;
public:
	Temperature();
	virtual void init(std::shared_ptr<Adapter> adapter);
	void linkMediator(std::shared_ptr<iot::LinkMediator> mediator);
	virtual void update(std::string observableName, std::string extra);
	void toDatabase();
	virtual ~Temperature();
};

} /* namespace adapter */
} /* namespace app */

#endif /* APP_ADAPTERS_TEMPERATURE_TEMPERATURE_H_ */
