/*
 * View.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_VIEW_H_
#define LIB_IOT_VIEW_H_

#include "modules/Observer/Observable.h"

namespace iot {

class View: public Observable {
public:
	View();
	virtual ~View();
};

} /* namespace iot */

#endif /* LIB_IOT_VIEW_H_ */
