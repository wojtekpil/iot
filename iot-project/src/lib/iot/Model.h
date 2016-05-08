/*
 * Model.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODEL_H_
#define LIB_IOT_MODEL_H_

#include "modules/Observer/Observable.h"
#include <memory>
#include "modules/Logger/Logger.h"

namespace iot {

class Model: public Observable {
protected:
	/**
	 * Shorthand for LoggerFactory
	 * @return
	 */
	std::shared_ptr<Logger> log();
public:
	Model();
	virtual ~Model();
};

} /* namespace iot */

#endif /* LIB_IOT_MODEL_H_ */
