/**
 * @file objectfactory.h
 * @brief
 * @author David Zatloukal
 * @date 1.5.2024
 */

#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "SessionManager.h"
#include "obstacle.h"
#include "robot.h"

class ObjectFactory
{
public:
    MapObject* createMapObject(SessionManager::obstacle* obstStruct, SessionManager::robot* robot, QGraphicsScene* scene);
};

#endif // OBJECTFACTORY_H
