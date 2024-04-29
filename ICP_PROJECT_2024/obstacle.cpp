#include "obstacle.h"
#include "qgraphicsscene.h"

Obstacle::Obstacle(size_t x, size_t y, size_t width, int angle, QGraphicsItem* obstacleGraphic)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->obstacleGraphic = obstacleGraphic;
    this->angle = angle;
}
void Obstacle::draw(QGraphicsScene* scene)
{
    //TODO: box, not rotated
    scene->removeItem(this->obstacleGraphic);
    this->obstacleGraphic = scene->addRect(this->x,this->y,width,width);
    this->obstacleGraphic->setTransformOriginPoint(QPoint(this->x + this->width/2,this->y +this->width/2));
    this->obstacleGraphic->setRotation(this->obstacleGraphic->rotation() + this->angle);
}
