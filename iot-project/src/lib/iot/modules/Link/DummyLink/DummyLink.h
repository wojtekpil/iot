/*
 * DummyLink.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_LINK_DUMMYLINK_DUMMYLINK_H_
#define LIB_IOT_MODULES_LINK_DUMMYLINK_DUMMYLINK_H_

#include "../Link.h"
#include <memory>
#include "../../Logger/Logger.h"

namespace iot {

class DummyLink: public Link {
private:
	std::shared_ptr<Logger> log();
public:
	DummyLink();
	virtual bool connect(std::string conf, LinkMediator* mediator);
	virtual bool disconnect();
	virtual bool isRunning();
	virtual bool send(std::shared_ptr<Spacket> packet);
	virtual bool read(std::shared_ptr<Spacket> packet);
	virtual ~DummyLink();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_LINK_DUMMYLINK_DUMMYLINK_H_ */
