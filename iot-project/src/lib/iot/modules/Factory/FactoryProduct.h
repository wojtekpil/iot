/*
 * FactoryProduct.h
 * Abstract Class for AbstractFactory Products
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_FACTORY_FACTORYPRODUCT_H_
#define LIB_IOT_MODULES_FACTORY_FACTORYPRODUCT_H_

#include <string>

namespace iot {

class FactoryProduct {
protected:
	std::string _uniqueName;
public:
	FactoryProduct();
	std::string getUniqueName();
	virtual ~FactoryProduct();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_FACTORY_FACTORYPRODUCT_H_ */
