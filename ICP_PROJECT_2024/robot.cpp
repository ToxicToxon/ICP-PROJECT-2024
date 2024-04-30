#include "robot.h"
#include "qgraphicsscene.h"
#include <QDebug>

Robot::Robot(int index,int speed, int type, int width, int orientation, int x, int y, int detection, int rotationAngle, int rotationDirection, QGraphicsItemGroup* robotGraphic)
{
    this->index = index;
    this->type = type;
    this->width = width;
    this->orientation = orientation;
    this->x = x;
    this->y = y;
    this->detection = detection;
    this->rotationAngle = rotationAngle;
    this->currentAngle = rotationAngle;
    this->rotationDirection = rotationDirection;
    this->robotGraphic = robotGraphic;
    this->speed = speed;
}

void Robot::move()
{
    //get new position using angle in radians
    this->x += (int)((double)this->speed*cos(double(this->currentAngle) /57.3));
    this->y += (int)((double)this->speed*(-sin(double(this->currentAngle) /57.3)));
}

int Robot::getType()
{
    return this->type;
}

void Robot::turn(bool turn)
{
    qDebug() << "turning?";
    if(turn == false)
        this->currentAngle += this->rotationAngle;
    else
        this->currentAngle -= this->rotationAngle;
    qDebug() << this->rotationAngle;
}

void Robot::draw(QGraphicsScene* scene)
{
    //moving circle
     qDebug() << this->rotationAngle;
    scene->removeItem(this->robotGraphic);
    QGraphicsItem* ellipse = scene->addEllipse(this->x, this->y, this->width, this->width);
    //detection rectangle
    QGraphicsItem* rectangle = scene->addRect(this->x + this->width, this->y, this->detection, this->width);
    rectangle->setTransformOriginPoint(QPoint(this->x + this->width/2,this->y +this->width/2));
    rectangle->setRotation(rectangle->rotation() + (-this->currentAngle));
    this->robotGraphic = scene->createItemGroup({ellipse, rectangle});
    this->move();
}
