/*
 * Bootstrap.h
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_BOOTSTRAP_H_
#define LIB_IOT_BOOTSTRAP_H_

namespace app {

/**
 * Bootstraps application for specific use
 */
class Bootstrap {
public:
	Bootstrap();
	void run_app();
	virtual ~Bootstrap();
};

} /* namespace iot */

#endif /* LIB_IOT_BOOTSTRAP_H_ */
