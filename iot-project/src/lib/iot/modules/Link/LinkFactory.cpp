/*
 * LinkFactory.cpp
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#include "LinkFactory.h"
#include "../Exception/Exception.h"
#include "DummyLink/DummyLink.h"

namespace iot {

LinkFactory::LinkFactory() {
	//add your links here
	this->registerCreator(std::shared_ptr<Link>(new DummyLink()));
}
/**
 * Generates logger using config value
 */
std::shared_ptr<Link> LinkFactory::createProduct(std::string type) {
	//if config is set and logger with given name exists
	if (!type.empty() && this->_links.find(type) != this->_links.end()) {
		return this->_links[type];
	} else {
		throw Exception("No valid Link is set! Please configure it in your bootstrap file: " + type);
	}
}

/**
 * Register acessible loggers
 */
void LinkFactory::registerCreator(std::shared_ptr<Link> factoryProduct) {
	//register logger to avaible list
	this->_links[(factoryProduct->getUniqueName())] = factoryProduct;
}

LinkFactory::~LinkFactory() {
}

} /* namespace iot */
