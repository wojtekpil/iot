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
/**
 * MVA Model class should be observed by Adapter class.
 * All models in app should inherit from this abstract class
 */
class Model: public Observable {
protected:
	std::shared_ptr<Logger> log();
public:
	Model();
	virtual ~Model();
};

} /* namespace iot */

#endif /* LIB_IOT_MODEL_H_ */
