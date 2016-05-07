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
	static bool registerModel(std::string name, ModelCreator* modelCreator);
	static std::shared_ptr<Model> produce(std::string name, std::string config);
	static void destroyCreators();
	virtual ~ModelFactory();
};

} /* namespace iot */

#endif /* LIB_IOT_MODELFACTORY_H_ */
