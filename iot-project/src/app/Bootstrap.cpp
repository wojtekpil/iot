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
#include "Models/Temperature/TemperatureCreator.h"
#include "Adapters/Temperature/Temperature.h"
//for testing
#include "Models/Temperature/Temperature.h"

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
	//model creators
	iot::ModelFactory::registerModel("Temperature",  new model::TemperatureCreator());

	auto temp = std::make_shared<adapter::Temperature>();
	temp->init(temp);

	//some testing
	auto tempM = std::dynamic_pointer_cast<app::model::Temperature>(iot::ModelFactory::produce("Temperature",""));
	tempM->makeEvent();

	core.run();

}


Bootstrap::~Bootstrap() {
}


} /* namespace iot */

