#ifndef ROBOT_H
#define ROBOT_H

#include "obstacle.h"
#include <QGraphicsItem>
#include <vector>
#include "SessionManager.h"
class Robot : public MapObject
{
public:
    Robot(int speed, SessionManager::robot robot, QGraphicsScene* scene);
    void draw(QGraphicsScene* scene, std::vector<Obstacle*> obstacleBuffer, std::vector<Robot*> robotBuffer);
    void move();
    void rotateLeft();
    void rotateRight();
    void turn(bool turn);
    void collision(bool objectType, bool detection); //true = obstacle, false = robot, true = detection, false = body
    int getType();
    QGraphicsItem* getGraphic();
    void go();
    void stop();

private:
    int type;
    int speed;
    int detection;
    double expectedAngle;
    double rotationAngle;
    bool rotationDirection; //false = left, true = right
    QGraphicsItemGroup* robotGraphic;
    QGraphicsItem* getDetection(std::vector<Obstacle*> obstacleBuffer, std::vector<Robot*> robotBuffer, QGraphicsScene* scene, QGraphicsItem* ellipse);

};

#endif // ROBOT_H
