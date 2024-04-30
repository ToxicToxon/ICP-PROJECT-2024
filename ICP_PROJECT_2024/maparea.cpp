/**
 * @file maparea.cpp
 * @brief
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 29.4.2024
 */

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

void MapArea::AddRobot(QGraphicsScene* scene, SessionManager::robotData settings)
{
    QGraphicsItem* ellipse = scene->addEllipse(settings.X, settings.Y, settings.Width, settings.Width);
    QGraphicsItem* rectangle = scene->addRect(settings.X, settings.Y, settings.Detection, settings.Width);
    rectangle->setRotation(rectangle->rotation() + (-45));
    QGraphicsItemGroup* robotGraphic = scene->createItemGroup({ellipse, rectangle});
    this->robotBuffer.push_back(new Robot(this->robotBuffer.size(), 4, settings.Type, settings.Width, settings.Orientation, settings.X, settings.Y,
                                          settings.Detection, settings.RotationAngle, settings.RotationDirection, robotGraphic));
}

void MapArea::AddObstacle(QGraphicsScene* scene, SessionManager::obstacleData settings)
{
    this->obstacleBuffer.push_back(new Obstacle(settings.X, settings.Y, settings.Width, settings.Orientation,
                                                scene->addRect(settings.X, settings.Y, settings.Width, settings.Orientation)));
}

MapArea::~MapArea()
{}
