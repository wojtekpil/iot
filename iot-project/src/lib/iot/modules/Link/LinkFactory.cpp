/*
 * LinkFactory.cpp
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#include "LinkFactory.h"
#include "../Exception/Exception.h"
#include "DummyLink/DummyLink.h"
#include "TcpLink/TcpLink.h"
#include <iostream>

namespace iot {

LinkFactory::LinkFactory() {
	//add your links here
	this->registerCreator(std::shared_ptr<Link>(new DummyLink()));
	this->registerCreator(std::shared_ptr<Link>(new TcpLink()));
}
/**
 * Generates logger using config value
 */
std::shared_ptr<Link> LinkFactory::createProduct(std::string type) {
	std::cout<<type<<std::endl;
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
	std::cout<<"NAME:"<<factoryProduct->getUniqueName()<<std::endl;
}

LinkFactory::~LinkFactory() {
}

} /* namespace iot */
