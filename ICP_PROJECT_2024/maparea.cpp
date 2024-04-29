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
    qDebug() << this->robotBuffer.size(); //TODO: use items
    this->robotBuffer[0]->draw(scene);
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
    this->robotBuffer.push_back(new Robot(this->robotBuffer.size(), 10, 1, 20, 20, 500, 500, 10, 100, 45, scene->addEllipse(500, 500, 20,20)));
    qDebug()<< this->robotBuffer.size();
}

MapArea::~MapArea()
{}
