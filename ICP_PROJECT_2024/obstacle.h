#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "qgraphicsitem.h"
#include <cstddef>
class Obstacle
{
public:
    Obstacle(size_t x, size_t y, size_t width, int angle, QGraphicsItem* obstacleGraphic);
    void draw(QGraphicsScene* scene);

private:
    size_t width;
    size_t x;
    size_t y;
    int angle;
    QGraphicsItem* obstacleGraphic;
};

#endif // OBSTACLE_H
