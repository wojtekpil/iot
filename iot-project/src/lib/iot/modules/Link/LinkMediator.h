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
	/**
	 * Register Link type in LinkMediator for communication between Device Model and Link
	 * @param link
	 * @return
	 */
	bool registerLink(std::shared_ptr<Link> link);
	/**
	 * Register connection between Device Model, Link using given Translator (from link to model)
	 * @param config - describe link connection
	 * @param dev - device model
	 * @param trans - translator from link to model data
	 * @return
	 */
	bool registerDevice(Link::Sdevice config, std::shared_ptr<Device> dev, std::shared_ptr<Translator> trans);
	/**
	 * Removes link type from LinkMediator, doesnt work if Link is already in use
	 * @param link
	 * @return
	 */
	bool unregisterLink(std::shared_ptr<Link> link);
	/**
	 * Removes connection of Device Model and Link
	 * @param config - describe link connection
	 * @param dev - device model
	 * @return
	 */
	bool unregisterDevice(Link::Sdevice config, std::shared_ptr<Device> dev);
	void notify();
	virtual ~LinkMediator();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_LINK_LINKMEDIATOR_H_ */
