#ifndef ROBOT_H
#define ROBOT_H

#include <QGraphicsItem>
class Robot
{
public:
    Robot(int index, int speed, int type, int width, int orientation, int x, int y, int detection, int rotationAngle, int rotationDirection, QGraphicsItemGroup* robotGraphic);
    void draw(QGraphicsScene* scene);
    void move();
    void rotateLeft();
    void rotateRight();
    void turn(bool turn);
    int getType();

private:
    int index;
    int type;
    int speed;
    int width;
    int orientation;
    int x;
    int y;
    int detection;
    int currentAngle;
    int rotationAngle;
    int rotationDirection;
    QGraphicsItemGroup* robotGraphic;
};

#endif // ROBOT_H
