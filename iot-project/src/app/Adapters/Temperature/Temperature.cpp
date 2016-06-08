/*
 * Temperature.cpp
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#include "Temperature.h"
#include <memory>
#include "../../../lib/iot/ModelFactory.h"
#include "../../Models/Temperature/Temperature.h"
#include "../../../lib/iot/modules/Database/Database.h"
#include "../../../lib/iot/modules/Database/SQLiteDatbase/SQLiteDatabase.h"
#include "../../../lib/iot/modules/Exception/Exception.h"

namespace app {
namespace adapter {

Temperature::Temperature() {

}

void Temperature::init(std::shared_ptr<Adapter> adapter) {
	auto temp = iot::ModelFactory::produce("Temperature","");
	temp->atach(adapter);
}

void Temperature::update(std::string observableName, std::string extra) {
	this->log()->debug("app::adapter::Temperature: Event from: " + observableName+ " with message: "+ extra);
	if(observableName == "app::model::Temperature") {
		this->toDatabase();
	}
	if(extra == "send_me_msg") {

	}

}

void Temperature::toDatabase() {
	auto tempM = std::dynamic_pointer_cast<app::model::Temperature>(iot::ModelFactory::produce("Temperature",""));
	std::string temp = tempM->getTemperature();
	auto db = std::make_shared<iot::SQLiteDatabase>();
	try {
		db->connect("iot.db");
		db->execute("INSERT INTO `temps` (temp) VALUES ('"+temp+"');");
	} catch (iot::Exception ex) {
		this->log()->error("app::adapter::Temperature: couldn't insert into database" + ex.getMsg());
	}

}

void Temperature::linkMediator(std::shared_ptr<iot::LinkMediator> mediator) {
	this->_mediator = mediator;
}

Temperature::~Temperature() {
}

} /* namespace adapter */
} /* namespace app */


