/**
 * @file mapobject.h
 * @brief
 * @author David Zatloukal
 * @date
 */

#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <QGraphicsItem>

class MapObject
{
public:
    //abstract class
    virtual QGraphicsItem* getGraphic() = 0;

    size_t width;
    double orientation;
    double x;
    double y;
};

#endif // MAPOBJECT_H
