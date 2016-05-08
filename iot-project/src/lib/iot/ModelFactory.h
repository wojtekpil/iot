/*
 * ModelFactory.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODELFACTORY_H_
#define LIB_IOT_MODELFACTORY_H_

#include <string>
#include <map>
#include "Model.h"
#include "ModelCreator.h"
namespace iot {

class ModelFactory {
private:
	static std::map<std::string, std::shared_ptr<Model>> _models;
	static std::map<std::string, ModelCreator*> _modelCreators;
public:
	ModelFactory();
	/**
	 * Register Model (by ModelCreator object) in Factory
	 * @param name - unique name of the Model
	 * @param modelCreator - constructor of specific Model
	 * @return
	 */
	static bool registerModel(std::string name, ModelCreator* modelCreator);
	/**
	 * Creates model using name and config, if model with given name and config exists, returns its instance
	 * @param name - name of the model to produces
	 * @param config - config string of model
	 * @return
	 */
	static std::shared_ptr<Model> produce(std::string name, std::string config);

	/**
	 * Free memory of ModelCreators
	 */
	static void destroyCreators();
	virtual ~ModelFactory();
};

} /* namespace iot */

#endif /* LIB_IOT_MODELFACTORY_H_ */
