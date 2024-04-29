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
    void AddObstacle();
    void removeRobot();
    void removeObstacle();
    size_t getWidth();
    size_t getHeight();
    std::vector<Robot*> robotBuffer; //TODO: move to private
private:
    size_t width;
    size_t height;
    std::vector<Obstacle*> obstacleBuffer;
    void drawTick(QGraphicsScene* scene, QGraphicsView* view);
};

#endif // MAPAREA_H
