/**
 * @file maparea.h
 * @brief
 * @author David Zatloukal
 * @author Ondřej Beneš
 * @date 29.4.2024
 */

#ifndef MAPAREA_H
#define MAPAREA_H

#include <cstddef>
#include <vector>
#include "robot.h"
#include "obstacle.h"
#include <QGraphicsScene>
#include "SessionManager.h"
class MapArea
{
public:
    MapArea(size_t width, size_t height);
    ~MapArea();
    void drawMap(QGraphicsScene* scene);
    void setBorders(QGraphicsScene* scene, size_t x, size_t y);
    void addRobot(QGraphicsScene* scene, SessionManager::robotData settings);
    void addObstacle(QGraphicsScene* scene, SessionManager::obstacleData settings);
    void turnAllUserRobots(bool turn); //false = left, true = right
    void goAllUserRobots();
    void stopAllUserRobots();
    void removeRobot();
    void removeObstacle();
    size_t getWidth();
    size_t getHeight();


private:
    size_t width;
    size_t height;
    std::vector<Robot*> robotBuffer;
    std::vector<Obstacle*> obstacleBuffer;
    void drawTick(QGraphicsScene* scene, QGraphicsView* view);
};

#endif // MAPAREA_H
