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
    if(type == 1)
        this->speed = 0;
    else
        this->speed = speed;
}

void Robot::move()
{
    //get new position using angle in radians
    this->x += (int)((double)this->speed*cos(this->currentAngle /57.3));
    this->y += (int)((double)this->speed*(-sin(this->currentAngle /57.3)));
}

void Robot::stop()
{
    this->speed = 0;
}

void Robot::go()
{
    qDebug() << "gotta go fast";
    this->speed = 4;
}

int Robot::getType()
{
    return this->type;
}

void Robot::turn(bool turn)
{
    if(turn == false)
        this->expectedAngle += this->rotationAngle;
    else
        this->expectedAngle -= this->rotationAngle;
}

QGraphicsItem* Robot::getGraphic()
{
    return this->robotGraphic;
}

void Robot::draw(QGraphicsScene* scene, std::vector<Obstacle*> obstacleBuffer, std::vector<Robot*> robotBuffer)
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
    //collisions for robot bodies
    QList<QGraphicsItem*> collidingItems = ellipse->collidingItems();
    if (!collidingItems.isEmpty())
    {
        //collisions between bodies and obstacles
        for(Obstacle* obstacle: obstacleBuffer)
        {
            for(QGraphicsItem* collidingItem: collidingItems)
            {
                if(obstacle->getGraphic() == collidingItem)
                {
                    this->collision(true, false);
                    break;
                }
            }
        }
    }
    //detection rectangle
    QGraphicsItem* rectangle = scene->addRect(this->x + this->width, this->y, this->detection, this->width);
    rectangle->setTransformOriginPoint(QPoint(this->x + this->width/2,this->y +this->width/2));
    rectangle->setRotation(rectangle->rotation() + (-this->currentAngle));
    //collisions with obstacles
    collidingItems = rectangle->collidingItems();
    bool stopFlag = false;
    for(Obstacle* obstacle: obstacleBuffer)
    {
        for(QGraphicsItem* collidingItem: collidingItems)
        {
            if(obstacle->getGraphic() == collidingItem)
            {
                this->collision(true, true);
                stopFlag = true;
                break;
            }
        }
        //collisions with bodies
        if(!stopFlag)
        {
            for(Robot* robot: robotBuffer)
            {
                for(QGraphicsItem* collidingItem: collidingItems)
                {
                    if(collidingItem == ellipse)
                        continue;
                    if(robot->getGraphic() == collidingItem)
                    {
                        this->collision(false, true);
                        break;
                    }
                }
            }
        }
    }
    if(collidingItems.size() == 1 && this->type == 0)
        this->go();
    this->robotGraphic = scene->createItemGroup({ellipse, rectangle});
    this->move();
}

void Robot::collision(bool objectType, bool detection)
{
    if(objectType && this->type == 1 && detection) // detection and obstacle controlled
        this->stop();
    else if(objectType && this->type == 1 && !detection) //body and obstacle controlled
        this->stop();
    else if(!objectType && this->type == 1 && detection) //body and detection controlled
        this->stop();
    else if(this->type == 0 && objectType && !detection) //body and obstacle
        this->stop();
    else if (this->type == 0 && objectType && detection) //detection and obstacle
    {
        this->stop();
        if(this->expectedAngle == this->currentAngle)
            this->turn(this->rotationDirection);
    }
    else if(this->type == 0 && !objectType && detection) //body and detection
    {
        this->stop();
        if(this->expectedAngle == this->currentAngle)
            this->turn(this->rotationDirection);
    }
}
