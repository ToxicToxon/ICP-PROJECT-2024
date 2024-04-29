#ifndef ROBOT_H
#define ROBOT_H

#include <QGraphicsItem>
class Robot
{
public:
    Robot(int index, int type, int width, int orientation, int x, int y, int detection, int rotationAngle, int rotationDirection, QGraphicsItem* robotEllipse);
    void draw();
    void move();
    void rotateLeft();
    void rotateRight();

private:
    int index;
    int type;
    int width;
    int orientation;
    int x;
    int y;
    int detection;
    int rotationAngle;
    int rotationDirection;
    QGraphicsItem* robotEllipse;
};

#endif // ROBOT_H
