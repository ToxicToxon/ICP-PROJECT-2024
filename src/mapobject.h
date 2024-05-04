/**
 * @file mapobject.h
 * @brief Parent class for obstacles and robots
 * @author David Zatloukal
 * @date 1.5.2024
 */

#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <QGraphicsItem>

class MapObject
{
public:
    /*!
     * \brief Method to get objects shapes
     * \return Objects drawn shape
     */
    virtual QGraphicsItem* getGraphic() = 0;

    /*!
     * \brief Default destructor for MapObject
     */
    virtual ~MapObject(){};

    size_t width;

    double orientation;

    double x;

    double y;
};

#endif // MAPOBJECT_H
