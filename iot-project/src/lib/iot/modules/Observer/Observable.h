/*
 * Observable.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_OBSERVER_OBSERVABLE_H_
#define LIB_IOT_MODULES_OBSERVER_OBSERVABLE_H_

#include "Observer.h"
#include <memory>
#include <vector>
#include <mutex>

namespace iot {

class Observable {
protected:
	std::mutex _observableMutex;
	std::vector<std::shared_ptr<Observer>> _observers;
	std::string _name;
public:
	Observable();
	virtual bool atach(const std::shared_ptr<Observer> observer);
	virtual bool detach(const std::shared_ptr<Observer> observer);
	virtual void notify();
	virtual ~Observable();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_OBSERVER_OBSERVABLE_H_ */
