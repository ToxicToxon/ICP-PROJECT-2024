/**
 * @file maparea.cpp
 * @brief Implementations of MapArea methods
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 29.4.2024
 */

#include "maparea.h"

MapArea::MapArea(size_t width, size_t height)
{
    this->width = width;
    this->height = height;
    this->robotBuffer = {};
    this->obstacleBuffer = {};
    this->paused = false;
    this->mapObjectFactory = new ObjectFactory;
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


//add robot to buffer
void MapArea::addRobot(QGraphicsScene* scene, SessionManager::robotData settings)
{
    this->robotBuffer.push_back(dynamic_cast<Robot*>(this->mapObjectFactory->createMapObject(nullptr, &settings, scene)));
}


//add obstacle to buffer
void MapArea::addObstacle(QGraphicsScene* scene, SessionManager::obstacleData settings)
{
    this->obstacleBuffer.push_back(dynamic_cast<Obstacle*>(this->mapObjectFactory->createMapObject(&settings, nullptr, scene)));
}


void MapArea::setBorders(QGraphicsScene* scene, size_t x, size_t y)
{
    this->obstacleBuffer.push_back(new Obstacle(0, 0, 1, y, 0, scene)); // Left border
    this->obstacleBuffer.push_back(new Obstacle(x, 0, 1, y, 0, scene)); // Right border
    this->obstacleBuffer.push_back(new Obstacle(0, 0, x, 1, 0, scene)); // Top border
    this->obstacleBuffer.push_back(new Obstacle(0, y, x, 1, 0, scene)); // Bottom border
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
{
    //TODO: delete all vector fields
    /*for(Robot* robot:this->robotBuffer)
        delete robot;
    for(Obstacle* obstacle: this->obstacleBuffer)
        delete obstacle;
    */
    delete mapObjectFactory;
}
