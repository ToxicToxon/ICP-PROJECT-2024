#ifndef MAPAREA_H
#define MAPAREA_H

#include <cstddef>
#include <vector>
#include "robot.h"
#include "obstacle.h"
#include <QGraphicsScene>
class MapArea
{
public:
    MapArea(size_t width, size_t height);
    ~MapArea();
    void drawMap(QGraphicsScene* scene);
    void AddRobot(QGraphicsScene* scene);
    void AddObstacle(QGraphicsScene* scene);
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
