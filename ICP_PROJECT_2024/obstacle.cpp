/**
 * @file obstacle.cpp
 * @brief Implementations of Obstacle class methods
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 29.4.2024
 */

#include "obstacle.h"
#include "qgraphicsscene.h"

Obstacle::Obstacle(SessionManager::obstacle obstStruct, QGraphicsScene* scene)
{
    this->height = (size_t)obstStruct.Width;
    this->width = (size_t)obstStruct.Width;
    this->x = (size_t)obstStruct.X;
    this->y = (size_t)obstStruct.Y;
    this->orientation = (double)obstStruct.Orientation;
    this->obstacleGraphic = scene->addRect(obstStruct.X, obstStruct.Y, obstStruct.Width, obstStruct.Width);
    this->obstacleGraphic->setTransformOriginPoint(QPoint(this->x + this->width/2,this->y +this->width/2));
    this->obstacleGraphic->setRotation(this->obstacleGraphic->rotation() + this->orientation);
}


Obstacle::Obstacle(size_t x, size_t y, size_t width, size_t height, int orientation, QGraphicsScene* scene)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->orientation = orientation;
    this->obstacleGraphic = scene->addRect(x, y, width, height);
}


QGraphicsItem* Obstacle::getGraphic()
{
    return this->obstacleGraphic;
}


void Obstacle::draw(QGraphicsScene* scene)
{
    scene->removeItem(this->obstacleGraphic);
    this->obstacleGraphic = scene->addRect(this->x,this->y,width,height);
    this->obstacleGraphic->setBrush(Qt::black);
    this->obstacleGraphic->setTransformOriginPoint(QPoint(this->x + this->width/2,this->y +this->width/2));
    this->obstacleGraphic->setRotation(this->obstacleGraphic->rotation() + this->orientation);
}
