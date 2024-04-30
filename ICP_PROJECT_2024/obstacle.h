#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "qgraphicsitem.h"
#include <cstddef>
class Obstacle
{
public:
    Obstacle(size_t x, size_t y, size_t width, size_t height, int angle, QGraphicsItem* obstacleGraphic);
    void draw(QGraphicsScene* scene);
    QGraphicsItem* getGraphic();

private:
    size_t width;
    size_t height;
    size_t x;
    size_t y;
    int angle;
    QGraphicsItem* obstacleGraphic;
};

#endif // OBSTACLE_H
