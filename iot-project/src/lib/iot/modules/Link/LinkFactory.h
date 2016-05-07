/*
 * LinkFactory.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_LINK_LINKFACTORY_H_
#define LIB_IOT_MODULES_LINK_LINKFACTORY_H_

#include <memory>
#include <string>
#include <map>

#include "../Factory/Factory.h"
#include "Link.h"

namespace iot {

class LinkFactory: public Factory {
private:
	std::map<std::string, std::shared_ptr<Link> > _links;
	void registerCreator(std::shared_ptr<Link> factoryProduct);
public:
	LinkFactory();
	std::shared_ptr<Link> createProduct(std::string type);
	virtual ~LinkFactory();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_LINK_LINKFACTORY_H_ */
