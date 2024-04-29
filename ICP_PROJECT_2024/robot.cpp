#include "robot.h"

Robot::Robot(int index, int type, int width, int orientation, int x, int y, int detection, int rotationAngle, int rotationDirection, QGraphicsItem* robotEllipse)
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
}
