#include "objectfactory.h"

MapObject* ObjectFactory::createMapObject(SessionManager::obstacle* obstStruct, SessionManager::robot* robot, QGraphicsScene* scene)
{
    if(obstStruct != nullptr)
        return new Obstacle(*obstStruct, scene);
    if(robot != nullptr)
        return new Robot(3, *robot, scene);
    return nullptr;
}