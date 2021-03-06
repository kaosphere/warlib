#include "modelfactory.h"

using namespace std;
using namespace QLogger;

const QString ModelFactory::LOG_ID_INFO = "ModelFactory_info";
const QString ModelFactory::LOG_ID_TRACE = "ModelFactory_trace";
const QString ModelFactory::LOG_ID_WARN = "ModelFactory_warn";
const QString ModelFactory::LOG_ID_ERR = "ModelFactory_err";

ModelFactory::ModelFactory()
{
    QLoggerManager *manager = QLoggerManager::getInstance();
    manager->addDestination("./logs/lastrun.log", QStringList(LOG_ID_TRACE), QLogger::TraceLevel);
    manager->addDestination("./logs/lastrun.log", QStringList(LOG_ID_INFO), QLogger::InfoLevel);
    manager->addDestination("./logs/lastrun.log", QStringList(LOG_ID_ERR), QLogger::ErrorLevel);
    manager->addDestination("./logs/lastrun.log", QStringList(LOG_ID_WARN), QLogger::WarnLevel);
}

QMap<QString, ModelAbstract*> ModelFactory::factory_model_map = QMap<QString, ModelAbstract*>();

void ModelFactory::associateKeyToClass(const QString &key, ModelAbstract *mod)
{
    // Put every key in lower case to prevent finding the key if the folder containing
    // the model has a different case.
    if(factory_model_map.find(key.toLower()) == factory_model_map.end()) // key is not already in map
    {
        QLog_Info(LOG_ID_INFO, "AssociateKeyToClass : Registering key " + key.toLower());
        factory_model_map[key.toLower()] = mod; // add key - mod association in map
    }
}

ModelAbstract *ModelFactory::createEmptyModel(const QString &key)
{
    ModelAbstract* tmp = 0;
    QMap<QString, ModelAbstract*>::const_iterator it = factory_model_map.find(key.toLower());
    if(it != factory_model_map.end()) // key was found in map
    {
        QLog_Info(LOG_ID_INFO, "createEmptyModel() : Key found in map : " + key);
        tmp = (*it)->clone();
    }
    else
        QLog_Error(LOG_ID_ERR, "createEmptyModel() : Can't find key : " + key);
    return tmp;
}

//create the corresponding model type depending on the path
ModelAbstract *ModelFactory::createFromFile(const QString& path) const
{
	ModelAbstract* tmp = 0;
	//extracting type directly in the path
    QString s = path.section('/',-2,-2);        
    QMap<QString, ModelAbstract*>::const_iterator it = factory_model_map.find(s.toLower());

    if(it != factory_model_map.end()) // key was found in map
    {
        tmp = (*it)->clone();
        tmp = tmp->setFromFile(path);

        QLog_Info(LOG_ID_INFO, "createFromFile() : Key found in map : " + s.toLower());
    }
    else
        QLog_Error(LOG_ID_ERR, "createFromFile() : Can't find key in path : " + path);

    return tmp;
}

ModelAbstract* ModelFactory::createFromUI(const QString &key, const ParamsfromUImodel* params) const
{
    ModelAbstract* tmp = 0;
    QMap<QString, ModelAbstract*>::const_iterator it = factory_model_map.find(key.toLower());
    if(it != factory_model_map.end()) // key was found in map
    {
        tmp = (*it)->clone();
        tmp = tmp->setFromUI(params);
        QLog_Info(LOG_ID_INFO, "createFromUI() : Key found in map : " + key.toLower());
    }
    else
        QLog_Error(LOG_ID_ERR, "createFromFile() : Can't find key : " + key.toLower());

    return tmp;
}






