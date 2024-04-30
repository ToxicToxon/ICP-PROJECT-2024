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
    this->rotationAngle = (double)rotationAngle;
    this->currentAngle = (double)rotationAngle;
    this->expectedAngle = (double)rotationAngle;
    if(rotationDirection == 1)
        this->rotationDirection = false;
    else
        this->rotationDirection = true;
    this->robotGraphic = robotGraphic;
    this->speed = speed;
}

void Robot::move()
{
    //get new position using angle in radians
    this->x += (int)((double)this->speed*cos(this->currentAngle /57.3));
    this->y += (int)((double)this->speed*(-sin(this->currentAngle /57.3)));
}

int Robot::getType()
{
    return this->type;
}

void Robot::turn(bool turn)
{
    if(turn == false)
    {
        this->expectedAngle += this->rotationAngle;
        this->rotationDirection = 1;
    }
    else
    {
        this->expectedAngle -= this->rotationAngle;
        this->rotationDirection = 2;
    }
}

void Robot::draw(QGraphicsScene* scene)
{
    //moving circle
    scene->removeItem(this->robotGraphic);
    //smooth turns
    double turningSpeed = this->rotationAngle*0.05;
    if(turningSpeed < 0)
        turningSpeed = -turningSpeed;
    if(turningSpeed > 2)
        turningSpeed = 2;
    if(turningSpeed < 0.75)
        turningSpeed = 0.75;
    if(this->currentAngle < this->expectedAngle - 5)
        this->currentAngle += turningSpeed;
    else if(this->currentAngle > this->expectedAngle + 5)
        this->currentAngle -= turningSpeed;
    else
        this->currentAngle = this->expectedAngle;
    QGraphicsItem* ellipse = scene->addEllipse(this->x, this->y, this->width, this->width);
    //detection rectangle
    QGraphicsItem* rectangle = scene->addRect(this->x + this->width, this->y, this->detection, this->width);
    rectangle->setTransformOriginPoint(QPoint(this->x + this->width/2,this->y +this->width/2));
    rectangle->setRotation(rectangle->rotation() + (-this->currentAngle));
    this->robotGraphic = scene->createItemGroup({ellipse, rectangle});
    this->move();
}
