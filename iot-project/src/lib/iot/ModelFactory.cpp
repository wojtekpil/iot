/*
 * ModelFactory.cpp
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#include "ModelFactory.h"
#include "modules/Exception/Exception.h"

namespace iot {

ModelFactory::ModelFactory() {

}
/**
 * Register Model (by ModelCreator object) in Factory
 * @param name - unique name of the Model
 * @param modelCreator - constructor of specific Model
 * @return
 */
bool ModelFactory::registerModel(std::string name, ModelCreator* modelCreator) {
	ModelFactory::_modelCreators[name] = modelCreator;
	return true;
}
/**
* Creates model using name and config, if model with given name and config exists, returns its instance
* @param name - name of the model to produces
* @param config - config string of model
* @return
*/
std::shared_ptr<Model> ModelFactory::produce(std::string name,
		std::string config) {
	// identification string to return exisiting Model if already created
	std::string dictionary = name + "=" + config;
	//find model in already created, if found return it
	auto iter_existing = ModelFactory::_models.find(dictionary);
	if (iter_existing != ModelFactory::_models.end()) {
		return iter_existing->second;
	}
	//no already created model found, so try to find model creator
	auto iter = ModelFactory::_modelCreators.find(name);
	if (iter != ModelFactory::_modelCreators.end()) {
		//model creator found
		std::shared_ptr<Model> model = iter->second->produce();
		//add model to models dictionary for future use
		ModelFactory::_models[dictionary] = model;
		return model;
	} else {
		//model creator not found!
		throw Exception("Model Creator name not found: " + name);
	}
}
/**
 * Free memory of ModelCreators
 */
void ModelFactory::destroyCreators() {
	std::map<std::string, ModelCreator*>::iterator itr = ModelFactory::_modelCreators.begin();
	while (itr != ModelFactory::_modelCreators.end()) {
		delete itr->second;
		ModelFactory::_modelCreators.erase(itr++);
	}
}

ModelFactory::~ModelFactory() {
}
//initialze static members
std::map<std::string, std::shared_ptr<Model>> ModelFactory::_models = []
{
	std::map<std::string, std::shared_ptr<Model>> ret;
    return ret;
}();

std::map<std::string, ModelCreator*> ModelFactory::_modelCreators = []
{
	std::map<std::string, ModelCreator*> ret;
    return ret;
}();

} /* namespace iot */
