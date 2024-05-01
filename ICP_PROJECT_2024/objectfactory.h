#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "obstacle.h"
#include "robot.h"
#include "SessionManager.h"

class ObjectFactory
{
public:
    MapObject* createMapObject(SessionManager::obstacle* obstStruct, SessionManager::robot* robot, QGraphicsScene* scene);
};

#endif // OBJECTFACTORY_H
