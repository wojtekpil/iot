/*
 * Observable.cpp
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#include "Observable.h"
#include <algorithm>

namespace iot {

Observable::Observable() {
}

/**
 * Atach new observer to observable object, thread safty aproach
 * @param observer - obsever object to add
 * @return
 */
bool Observable::atach(const std::shared_ptr<Observer> observer) {
	std::lock_guard<std::mutex> guard(this->_observableMutex);
	this->_observers.push_back(observer);
	return true;
}
/**
 * Remove  observer, thread safty aproach
 * @param observer - observer object to remove
 * @return
 */
bool Observable::detach(const std::shared_ptr<Observer> observer) {
	std::lock_guard<std::mutex> guard(this->_observableMutex);
	this->_observers.erase(std::remove(this->_observers.begin(), this->_observers.end(), observer), this->_observers.end());
	return true;
}

/**
 * Broadcast event to observers
 */
void Observable::notify(std::string extra) {
	//"copy and broadcast" // lock -> copy list -> unlock
	// http://stackoverflow.com/questions/14381588/observer-pattern-using-weak-ptr

	std::vector<std::shared_ptr<Observer>> targets;
	{
	  std::lock_guard<std::mutex> guard( this->_observableMutex );
	  this->_observers.erase( std::remove_if( this->_observers.begin(), this->_observers.end(),
	        [&targets]( const std::weak_ptr<Observer>& o )
	    {
	      std::shared_ptr<Observer> ptr = o.lock();
	      if (ptr) {
	        targets.push_back(ptr);
	        return false;
	      } else {
	        return true;
	      }
	    } ), this->_observers.end() );
	}

	for( auto& target:targets ) {
		target->update(this->_name, extra);
	}

}

Observable::~Observable() {
}

} /* namespace iot */
