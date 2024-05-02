#ifndef ROBOT_H
#define ROBOT_H

#include "obstacle.h"
#include "SessionManager.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <vector>
#include <QGraphicsScene>
#include <QDebug>

class Robot : public MapObject
{
public:
    Robot(int speed, SessionManager::robot robot, QGraphicsScene* scene);
    void draw(QGraphicsScene* scene, std::vector<Obstacle*> obstacleBuffer, std::vector<Robot*> robotBuffer);
    void move();
    void rotateLeft();
    void rotateRight();
    void turn(bool turn);
    void collision();
    int getType();
    QGraphicsItem* getGraphic() override;
    void go();
    void stop();

private:
    int type;
    int speed;
    int detection;
    bool stuck;
    double expectedAngle;
    double rotationAngle;
    bool rotationDirection; //false = left, true = right
    QGraphicsItemGroup* robotGraphic;
    QGraphicsItem* getDetection(std::vector<Obstacle*> obstacleBuffer, std::vector<Robot*> robotBuffer, QGraphicsScene* scene, QGraphicsItem* ellipse);
    QGraphicsEllipseItem* getBody(std::vector<Robot*> robotBuffer);

};

#endif // ROBOT_H
