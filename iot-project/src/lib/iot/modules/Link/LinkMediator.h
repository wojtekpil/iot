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
#include <thread>
#include <mutex>

#include "Link.h"
#include "../Device/Device.h"
#include "../Translator/Translator.h"

namespace iot {

class Link;
struct Sdevice;
struct Spacket;
/**
 * Manages connection between Links and Device Models
 */
class LinkMediator {
protected:
	struct SlinkDevice {
		std::shared_ptr<Device> dev;
		std::shared_ptr<Translator> trans;
		std::string linkName;
		Sdevice *conf;
	};
	std::vector<std::string> _links;
	std::vector<SlinkDevice> _devices;
	std::mutex _linkMutex;
	std::map<std::string, std::shared_ptr<Link> > _linkInstances;

public:
	LinkMediator();
	bool registerLink(std::string linkName);
	bool registerDevice(Sdevice config, std::shared_ptr<Device> dev, std::shared_ptr<Translator> trans);
	bool unregisterLink(std::string linkName);
	bool unregisterDevice(Sdevice config, std::shared_ptr<Device> dev);
	void notify(std::shared_ptr<Spacket> packet);
	void send(std::shared_ptr<Spacket> packet);
	void linkReader(std::string linkName);
	void start();
	void shutdown();
	virtual ~LinkMediator();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_LINK_LINKMEDIATOR_H_ */
