/*
 * LinkMediator.h
 *
 *  Created on: 8 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_LINK_LINKMEDIATOR_H_
#define LIB_IOT_MODULES_LINK_LINKMEDIATOR_H_
#include <memory>
#include <map>
#include <vector>
#include <mutex>

#include "Link.h"
#include "../Device/Device.h"
#include "../Translator/Translator.h"

namespace iot {
/**
 * Manages connection between Links and Device Models
 */
class LinkMediator {
protected:
	struct SlinkDevice {
		std::shared_ptr<Device> dev;
		std::shared_ptr<Translator> trans;
		std::shared_ptr<Link> link;
		Link::Sdevice conf;
	};
	std::map<std::string,std::shared_ptr<Link>> _links;
	std::vector<SlinkDevice> _devices;
	std::mutex _linkMutex;

public:
	LinkMediator();
	bool registerLink(std::shared_ptr<Link> link);
	bool registerDevice(Link::Sdevice config, std::shared_ptr<Device> dev, std::shared_ptr<Translator> trans);
	bool unregisterLink(std::shared_ptr<Link> link);
	bool unregisterDevice(Link::Sdevice config, std::shared_ptr<Device> dev);
	void notify();
	virtual ~LinkMediator();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_LINK_LINKMEDIATOR_H_ */
