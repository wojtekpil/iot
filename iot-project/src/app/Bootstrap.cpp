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

#include "Adapters/Temperature/Temperature.h"

namespace app {

Bootstrap::Bootstrap() {
	std::cout<<"Bootstraping"<<std::endl;

}

void Bootstrap::run_app() {
	iot::Core core;

	//bootstrap app here
	iot::Configs::getInstance().set("Logger", "ConsoleLogger");

	auto temp = std::make_shared<adapter::Temperature>();
	temp->init(temp);
	core.run();
}


Bootstrap::~Bootstrap() {
	// TODO Auto-generated destructor stub
}


} /* namespace iot */

