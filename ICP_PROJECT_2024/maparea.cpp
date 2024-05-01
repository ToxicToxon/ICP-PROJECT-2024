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
    this->paused = false;
}

void MapArea::drawMap(QGraphicsScene* scene)
{
    if(!paused)
    {
        //foreach cycle through each robot and obstacle, draw them, clear scene with every frame
        for(Robot* robot: this->robotBuffer)
            robot->draw(scene, this->obstacleBuffer, this->robotBuffer);
        for(Obstacle* obstacle: this->obstacleBuffer)
            obstacle->draw(scene);
    }
}

void MapArea::turnAllUserRobots(bool turn)
{
    for(Robot* robot : robotBuffer)
    {
        if(robot->getType() == 1)
            robot->turn(turn);
    }
}

void MapArea::stopAllUserRobots()
{
    for(Robot* robot : robotBuffer)
    {
        if(robot->getType() == 1)
            robot->stop();
    }
}

void MapArea::goAllUserRobots()
{
    for(Robot* robot : robotBuffer)
    {
        if(robot->getType() == 1)
            robot->go();
    }
}

size_t MapArea::getWidth()
{
    return this->width;
}

size_t MapArea::getHeight()
{
    return this->height;
}

void MapArea::addRobot(QGraphicsScene* scene, SessionManager::robotData settings)
{
    QGraphicsItem* ellipse = scene->addEllipse(settings.X, settings.Y, settings.Width, settings.Width);
    QGraphicsItem* rectangle = scene->addRect(settings.X, settings.Y, settings.Detection, settings.Width);
    rectangle->setRotation(rectangle->rotation() + (-settings.RotationAngle));
    QGraphicsItemGroup* robotGraphic = scene->createItemGroup({ellipse, rectangle});
    this->robotBuffer.push_back(new Robot(this->robotBuffer.size(), 3, settings.Type, settings.Width, settings.Orientation, settings.X, settings.Y,
                                          settings.Detection, settings.RotationAngle, settings.RotationDirection, robotGraphic));
}

void MapArea::addObstacle(QGraphicsScene* scene, SessionManager::obstacleData settings)
{
    this->obstacleBuffer.push_back(new Obstacle(settings.X, settings.Y, settings.Width, settings.Width, settings.Orientation,
                                                scene->addRect(settings.X, settings.Y, settings.Width, settings.Orientation)));
}

void MapArea::setBorders(QGraphicsScene* scene, size_t x, size_t y) {
    this->obstacleBuffer.push_back(new Obstacle(0, 0, 1, y, 0, scene->addRect(0, 0, 1, y))); // Left border
    this->obstacleBuffer.push_back(new Obstacle(x, 0, 1, y, 0, scene->addRect(x, 0, 1, y))); // Right border
    this->obstacleBuffer.push_back(new Obstacle(0, 0, x, 1, 0, scene->addRect(0, 0, x, 1))); // Top border
    this->obstacleBuffer.push_back(new Obstacle(0, y, x, 1, 0, scene->addRect(0, y, x, 1))); // Bottom border
}

void MapArea::pausePlay()
{
    if(!this->paused)
        this->paused = true;
    else
        this->paused = false;

}

bool MapArea::isPaused()
{
    return this->paused;
}
MapArea::~MapArea()
{}
