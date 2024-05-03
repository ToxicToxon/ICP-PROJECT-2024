/**
 * @file objectfactory.h
 * @brief Declaration of ObjectFactory class
 * @author David Zatloukal
 * @date 1.5.2024
 */

#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "SessionManager.h"
#include "mapobject.h"

class ObjectFactory
{
public:
    /*!
     * \brief Method to create MapObjects
     * \param obstStruct Structure with all the informations about an obstacle
     * \param robot Structure with all the informations about a robot
     * \param scene Current scene
     * \return Obstacle or Robot object
     */
    MapObject* createMapObject(SessionManager::obstacle* obstStruct, SessionManager::robot* robot, QGraphicsScene* scene);
};

#endif // OBJECTFACTORY_H
