#ifndef ROBOT_H
#define ROBOT_H

#include <QGraphicsItem>
class Robot
{
public:
    Robot(int index, int speed, int type, int width, int orientation, int x, int y, int detection, int rotationAngle, int rotationDirection, QGraphicsItem* robotEllipse);
    void draw(QGraphicsScene* scene);
    void move();
    void rotateLeft();
    void rotateRight();

private:
    int index;
    int type;
    int speed;
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
