/*
 * Link.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_LINK_LINK_H_
#define LIB_IOT_MODULES_LINK_LINK_H_

#include <memory>
#include <string>
#include "../Factory/FactoryProduct.h"
#include "LinkMediator.h"

namespace iot {

class LinkMediator;


struct Sdevice {
	uint32_t addr;
	std::string network_conf;
};
struct Spacket {
	Sdevice dev;
	uint32_t time;
	std::string message;
};

/**
 * Network Link abstract class
 */
class Link: public FactoryProduct{
protected:
	std::string _uniqueName="UnknownLink";
public:

	Link();
	virtual bool connect(std::string conf, LinkMediator* mediator)=0;
	virtual bool disconnect()=0;
	virtual bool isRunning()=0;
	virtual bool send(std::shared_ptr<Spacket> packet)=0;
	virtual bool read(std::shared_ptr<Spacket> packet)=0;
	virtual void update() {};
	virtual ~Link();
	const std::string& getName() const;

};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_LINK_LINK_H_ */
