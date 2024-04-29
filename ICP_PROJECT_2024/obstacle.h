#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <cstddef>
class Obstacle
{
public:
    Obstacle(size_t x, size_t y, size_t width);
    void draw();

private:
    size_t width;
    size_t x;
    size_t y;
};

#endif // OBSTACLE_H
