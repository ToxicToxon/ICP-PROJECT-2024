#include "obstacle.h"
#include "qgraphicsscene.h"

Obstacle::Obstacle(size_t x, size_t y, size_t width, size_t height, int angle, QGraphicsItem* obstacleGraphic)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->obstacleGraphic = obstacleGraphic;
    this->angle = angle;
}

QGraphicsItem* Obstacle::getGraphic()
{
    return this->obstacleGraphic;
}
void Obstacle::draw(QGraphicsScene* scene)
{
    //TODO: box, not rotated
    scene->removeItem(this->obstacleGraphic);
    this->obstacleGraphic = scene->addRect(this->x,this->y,width,height);
    this->obstacleGraphic->setTransformOriginPoint(QPoint(this->x + this->width/2,this->y +this->width/2));
    this->obstacleGraphic->setRotation(this->obstacleGraphic->rotation() + this->angle);
}
