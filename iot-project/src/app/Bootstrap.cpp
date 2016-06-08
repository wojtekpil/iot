/*
 * Bootstrap.cpp
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#include "Bootstrap.h"
#include <iostream>
#include "../lib/iot/Core.h"
#include "../lib/iot/modules/Configs/Configs.h"
#include "../lib/iot/ModelFactory.h"
#include "../lib/iot/modules/Link/LinkMediator.h"
#include "../lib/iot/modules/Translator/StandardTranslator/StandardTranslator.h"
#include "Models/Temperature/TemperatureCreator.h"
#include "Adapters/Temperature/Temperature.h"
//for testing
#include "Models/Temperature/Temperature.h"
#include "../lib/iot/modules/Link/Link.h"

namespace app {

Bootstrap::Bootstrap() {
	std::cout<<"Bootstraping"<<std::endl;

}

/**
 * Configure your application here
 */
void Bootstrap::run_app() {
	iot::Core core;
	//bootstrap app here
	iot::Configs::getInstance().set("Logger", "ConsoleLogger");


	auto lm = std::make_shared<iot::LinkMediator>();
	lm->registerLink("TcpLink");
	std::cout<<"Bootstraping after Register Link"<<std::endl;


	//model creators
	iot::ModelFactory::registerModel("Temperature",  new model::TemperatureCreator());



	auto temp = std::make_shared<adapter::Temperature>();
	temp->init(temp);

	// standard translator
	auto sTrans = std::make_shared<iot::StandardTranslator>();
	//some testing
	auto tempM = std::dynamic_pointer_cast<app::model::Temperature>(iot::ModelFactory::produce("Temperature",""));
	iot::Sdevice dev_conf;
	dev_conf.addr = 1234;
	dev_conf.network_conf="TcpLink";
	lm->registerDevice(dev_conf, tempM,sTrans);
	std::cout<<"Bootstraping after Register Device"<<std::endl;
	//tempM->makeEvent();
	core.run();
	std::cout<<"Bootstraping after Core Run"<<std::endl;
	lm->start();
	lm->shutdown();
	core.shutdown();
}


Bootstrap::~Bootstrap() {
}


} /* namespace iot */

