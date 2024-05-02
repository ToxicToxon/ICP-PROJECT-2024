/**
 * @file obstacle.h
 * @brief
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date
 */

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsItem>
#include <cstddef>
#include "SessionManager.h"
#include "mapobject.h"

class Obstacle: public MapObject
{
public:
    Obstacle(size_t x, size_t y, size_t width, size_t height, int orientation, QGraphicsScene* scene);
    Obstacle(SessionManager::obstacle obstStruct, QGraphicsScene* scene);
    QGraphicsItem* getGraphic();
    void draw(QGraphicsScene* scene);

private:
    size_t height;
    QGraphicsRectItem* obstacleGraphic;
};

#endif // OBSTACLE_H
