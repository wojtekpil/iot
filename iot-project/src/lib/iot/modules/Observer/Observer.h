/*
 * Observer.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_OBSERVER_OBSERVER_H_
#define LIB_IOT_MODULES_OBSERVER_OBSERVER_H_

#include <string>

namespace iot {

/**
 * Observer abstract class can observe Observable classes
 */
class Observer {
public:
	Observer();
	virtual void update(std::string observableName)=0;
	virtual ~Observer();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_OBSERVER_OBSERVER_H_ */
