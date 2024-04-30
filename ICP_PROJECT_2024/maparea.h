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
    void AddRobot(QGraphicsScene* scene, SessionManager::robotData settings);
    void AddObstacle(QGraphicsScene* scene, SessionManager::obstacleData settings);
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
