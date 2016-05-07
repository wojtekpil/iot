/*
 * Adapter.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_ADAPTER_H_
#define LIB_IOT_ADAPTER_H_

#include <memory>
#include <vector>
#include "modules/Observer/Observer.h"
#include "Model.h"
#include "View.h"
#include "modules/Logger/Logger.h"


namespace iot {

class Adapter: public Observer {
protected:
	/**
	 * Shorthand for LoggerFactory
	 */
	std::shared_ptr<Logger> log();
public:
	Adapter();
	virtual void init(std::shared_ptr<Adapter> adapter)=0;
	virtual void update(std::string observableName)=0;
	virtual ~Adapter();
};

} /* namespace iot */

#endif /* LIB_IOT_ADAPTER_H_ */
