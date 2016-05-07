/*
 * Core.h
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_CORE_H_
#define LIB_IOT_CORE_H_

namespace iot {

class Core {
public:
	Core();
	virtual void run();
	virtual void shutdown();
	virtual ~Core();
};

} /* namespace iot */

#endif /* LIB_IOT_CORE_H_ */
