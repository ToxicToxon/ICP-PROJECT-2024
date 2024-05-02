#include "robot.h"
#include <cmath>

Robot::Robot(int speed, SessionManager::robot robot, QGraphicsScene* scene)
{
    this->type = robot.Type;
    this->width = (size_t)robot.Width;
    this->x = robot.X;
    this->y = robot.Y;
    this->detection = robot.Detection;
    this->rotationAngle = (double)robot.RotationAngle;
    this->orientation = (double)robot.Orientation;
    this->expectedAngle = (double)robot.Orientation;
    if(robot.RotationDirection == 1)
        this->rotationDirection = false;
    else
        this->rotationDirection = true;
    if(robot.Type == 1)
        this->speed = 0;
    else
        this->speed = speed;
    //draw robot and put him in the scene
    QGraphicsItem* ellipse = scene->addEllipse(this->x, this->y, this->width, this->width);
    QGraphicsItem* rectangle = scene->addRect(this->x+this->width, this->y, this->detection, this->width);
    rectangle->setRotation(rectangle->rotation() + (-this->orientation));
    rectangle->setTransformOriginPoint(QPoint(this->x + this->width/2,this->y + this->width/2 ));
    QGraphicsItemGroup* robotGraphic = scene->createItemGroup({ellipse, rectangle});
    this->robotGraphic = robotGraphic;
}

void Robot::move()
{
    //get new position using angle in radians
    this->x += (double)this->speed*cos(this->orientation /57.29578);
    this->y += (double)this->speed*(-sin(this->orientation /57.29578));
}

void Robot::stop()
{
    this->speed = 0;
}

void Robot::go()
{
    this->speed = 3;
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

QGraphicsItem* Robot::getDetection( std::vector<Obstacle *> obstacleBuffer, std::vector<Robot *> robotBuffer, QGraphicsScene* scene, QGraphicsItem* ellipse)
{
    QGraphicsRectItem* rect = scene->addRect(this->x + this->width, this->y, this->detection, this->width);

    // colors
    QPen detectionPen(Qt::green);
    detectionPen.setStyle(Qt::DashLine);
    rect->setPen(detectionPen);
    rect->setTransformOriginPoint(QPoint(this->x + this->width/2,this->y + this->width/2 ));
    rect->setRotation(rect->rotation() + (-this->orientation));

    // collisions with obstacles
    QList<QGraphicsItem*> collidingItems;
    collidingItems = rect->collidingItems();
    bool stopFlag = false;
    for(Obstacle* obstacle: obstacleBuffer)
    {
        for(QGraphicsItem* collidingItem: collidingItems)
        {
            if(obstacle->getGraphic() == collidingItem)
            {
                dynamic_cast<QGraphicsEllipseItem*>(ellipse)->setBrush(QBrush(Qt::darkRed));
                this->collision();
                stopFlag = true;
                break;
            }
        }
        // collisions with robot bodies
        if(!stopFlag)
        {
            for(Robot* robot: robotBuffer)
            {
                for(QGraphicsItem* collidingItem: collidingItems)
                {
                    if(collidingItem == ellipse) {
                        continue;
                    }
                    if(robot->getGraphic()->childItems()[0] == collidingItem)
                    {
                        dynamic_cast<QGraphicsEllipseItem*>(ellipse)->setBrush(QBrush(Qt::darkRed));
                        this->collision();
                        break;
                    }
                }
            }
        }
    }
    return rect;
}

void Robot::draw(QGraphicsScene* scene, std::vector<Obstacle*> obstacleBuffer, std::vector<Robot*> robotBuffer)
{
    // moving circle
    scene->removeItem(this->robotGraphic);

    // smooth turns
    double turningSpeed = this->rotationAngle*0.05;
    if(turningSpeed < 0)
        turningSpeed = -turningSpeed;
    if(turningSpeed > 2)
        turningSpeed = 2;
    if(turningSpeed < 0.75)
        turningSpeed = 0.75;
    if(this->orientation < this->expectedAngle - 5)
        this->orientation += turningSpeed;
    else if(this->orientation > this->expectedAngle + 5)
        this->orientation -= turningSpeed;
    else
    {
        this->expectedAngle = fmod(this->expectedAngle, 360);
        this->orientation = this->expectedAngle;
    }

    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(this->x, this->y, this->width, this->width);
    if(type == 0)
    {
        QList<QGraphicsItem*> collidingItems;
        for(Robot* robot: robotBuffer)
        {
            for(QGraphicsItem* collidingItem: collidingItems)
            {
                if(robot->getGraphic()->childItems()[0] == collidingItem)
                {
                    this->collision();
                    break;
                }
            }
        }
    }
    if (type == 1) {
        ellipse->setBrush(QBrush(Qt::darkCyan));
    }
    else {
        ellipse->setBrush(QBrush(Qt::darkGreen));
    }
    ellipse->setPen(Qt::NoPen);
    this->robotGraphic = scene->createItemGroup({ellipse});
    this->robotGraphic->addToGroup(this->getDetection(obstacleBuffer, robotBuffer, scene, ellipse));
    if(this->type == 0  && this->orientation == this->expectedAngle)
    {
        this->go();
    }
    this->move();
}


/*!
 * \brief Switches movement
 */
void Robot::collision()
{
    if(this->type == 1)
        this->stop();
    else if (this->type == 0)
    {
        this->stop();
        if(this->expectedAngle == this->orientation)
            this->turn(this->rotationDirection);
    }
}
