#ifndef ROBOT_H
#define ROBOT_H

#include "obstacle.h"
#include <QGraphicsItem>
#include <vector>
class Robot
{
public:
    Robot(int index, int speed, int type, int width, int orientation, int x, int y, int detection, int rotationAngle, int rotationDirection, QGraphicsItemGroup* robotGraphic);
    void draw(QGraphicsScene* scene, std::vector<Obstacle*> obstacleBuffer, std::vector<Robot*> robotBuffer);
    void move();
    void rotateLeft();
    void rotateRight();
    void turn(bool turn);
    void collision(bool objectType, bool detection); //true = obstacle, false = robot, true = detection, false = body
    int getType();
    void go();
    void stop();
    QGraphicsItem* getGraphic();

private:
    int index;
    int type;
    int speed;
    int width;
    int orientation;
    double x;
    double y;
    int detection;
    double currentAngle;
    double expectedAngle;
    double rotationAngle;
    bool rotationDirection; //false = left, true = right
    QGraphicsItemGroup* robotGraphic;
    QGraphicsItem* getDetection(std::vector<Obstacle*> obstacleBuffer, std::vector<Robot*> robotBuffer, QGraphicsScene* scene, QGraphicsItem* ellipse);

};

#endif // ROBOT_H
