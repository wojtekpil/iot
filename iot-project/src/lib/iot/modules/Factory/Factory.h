/*
 * Factory.h
 * Inteface for Abstract Factory
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_FACTORY_FACTORY_H_
#define LIB_IOT_MODULES_FACTORY_FACTORY_H_

#include "FactoryProduct.h"
#include <memory>

namespace iot {

class Factory {
public:
	Factory();
	virtual ~Factory();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_FACTORY_FACTORY_H_ */
