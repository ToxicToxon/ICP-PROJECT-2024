#include "maparea.h"
#include <QDebug>

MapArea::MapArea(size_t width, size_t height)
{
    this->width = width;
    this->height = height;
    this->robotBuffer = {};
    this->obstacleBuffer = {};
}

void MapArea::drawMap(QGraphicsScene* scene)
{
    //foreach cycle through each robot and obstacle, draw them, clear scene with every frame
    for(Robot* robot: this->robotBuffer)
        robot->draw(scene);
    for(Obstacle* obstacle: this->obstacleBuffer)
        obstacle->draw(scene);
}

size_t MapArea::getWidth()
{
    return this->width;
}

size_t MapArea::getHeight()
{
    return this->height;
}

void MapArea::AddRobot(QGraphicsScene* scene)
{
    QGraphicsItem* ellipse = scene->addEllipse(500, 500, 20,20);
    QGraphicsItem* rectangle = scene->addRect(500, 500, 80, 20);
    rectangle->setRotation(rectangle->rotation() + (-45));
    QGraphicsItemGroup* robotGraphic = scene->createItemGroup({ellipse, rectangle});
    this->robotBuffer.push_back(new Robot(this->robotBuffer.size(), 4, 1, 20, 20, 800, 800, 10, 145, 45, robotGraphic));
    qDebug()<< this->robotBuffer.size();
}

void MapArea::AddObstacle(QGraphicsScene* scene)
{
    this->obstacleBuffer.push_back(new Obstacle(800, 800, 45, 45, scene->addRect(800, 800, 45, 45)));
}

MapArea::~MapArea()
{}
