/*
 * ModelCreator.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODELCREATOR_H_
#define LIB_IOT_MODELCREATOR_H_

#include <string>

namespace iot {

class ModelCreator {
public:
	ModelCreator() {}
	/**
	 * Create specific Model
	 * @return specific Model ptr
	 */
	virtual std::shared_ptr<Model> produce()=0;
	virtual ~ModelCreator() {}
};

} /* namespace iot */

#endif /* LIB_IOT_MODELCREATOR_H_ */
