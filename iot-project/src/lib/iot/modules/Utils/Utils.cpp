/*
 * Utils.cpp
 *
 *  Created on: 6 maj 2016
 *      Author: wojtek
 */

#include "Utils.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace iot {

static Utils utils;

Utils::Utils() {
	onStartup();
}

void Utils::onStartup() {
	//run random generator
	srand( time( NULL ) );
	std::cout<<"Utils kicks in!"<<std::endl;
}

Utils::~Utils() {
	// TODO Auto-generated destructor stub
}

} /* namespace iot */
