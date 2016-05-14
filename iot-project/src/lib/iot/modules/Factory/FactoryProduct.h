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
/**
 * Abstract class of factory product, each class produced by factory should inherit it
 */
class FactoryProduct {
protected:
	std::string _uniqueName="Unnamed";
public:
	FactoryProduct();
	std::string getUniqueName();
	void setUniqueName(std::string);
	virtual ~FactoryProduct();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_FACTORY_FACTORYPRODUCT_H_ */
