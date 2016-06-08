/*
 * StandardTranslator.cpp
 *
 *  Created on: 14 maj 2016
 *      Author: wojtek
 */

#include "StandardTranslator.h"
#include "../../Logger/LoggerFactory.h"
#include <vector>
#include <string>

namespace iot {

using std::string;
using std::vector;

StandardTranslator::StandardTranslator() {

}

vector<string> StandardTranslator::split(string str, const string& delimiter)
{
	vector<string> results;
	results.clear();
    size_t pos = 0;
    while ((pos = str.find(delimiter)) != string::npos) //znajdŸ pozycjê 'delimitera', jeœli siê da
    {
        results.push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.length()); //odetnij znaleziony 'delimiter' z orygina³u
    }
    if(str.length() > 0)
        results.push_back(str); //ewentualna koñcówka napisu
	return results;
}

Device::tDeviceData StandardTranslator::toSystem(std::string fromDev) {
	vector<string> args = this->split(fromDev, " ");
	Device::tDeviceData result;
	for(auto& line: args) {
		vector<string> ins = this->split(line, "=");
		if(ins.size() != 2) {
			LoggerFactory lf;
			lf.createProduct()->warn("Wrong message from device: " + line);
			continue;
		}
		result[ins.at(0)] = ins.at(1);
	}
	return result;
}

std::string StandardTranslator::toDevice(Device::tDeviceData fromSys) {
	// TODO implement outgoing messages
	return "To IMPLEMENT";
}

StandardTranslator::~StandardTranslator() {
}

} /* namespace iot */
