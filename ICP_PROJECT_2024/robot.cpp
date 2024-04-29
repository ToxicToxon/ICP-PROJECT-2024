#include "robot.h"
#include "qgraphicsscene.h"
#include <QDebug>

Robot::Robot(int index,int speed, int type, int width, int orientation, int x, int y, int detection, int rotationAngle, int rotationDirection, QGraphicsItem* robotEllipse)
{
    this->index = index;
    this->type = type;
    this->width = width;
    this->orientation = orientation;
    this->x = x;
    this->y = y;
    this->detection = detection;
    this->rotationAngle = rotationAngle;
    this->rotationDirection = rotationDirection;
    this->robotEllipse = robotEllipse;
    this->speed = speed;
}

void Robot::move()
{
    //To get radians
    this->x += (int)((double)this->speed*cos(double(this->rotationDirection) /57.3));
    this->y += (int)((double)this->speed*sin(double(this->rotationDirection) /57.3));
}

void Robot::draw(QGraphicsScene* scene)
{
    qDebug() << "test";
    scene->removeItem(this->robotEllipse);
    this->robotEllipse = scene->addEllipse(this->x,this->y,width,width);
    this->move();
    scene->removeItem(this->robotEllipse);
    this->robotEllipse = scene->addEllipse(this->x,this->y,width,width);
}
