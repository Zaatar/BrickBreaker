#ifndef BRICK_H
#define BRICK_H

#include "Square.h"

class Brick : public Square
{
public:
    void init(float xPos, float yPos);
    void destroy();

private:
    float brickScaleMatrix[16] = {
        0.2f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.1f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f};

    //const float XDISTANCE = 0.11;
    //const float YDISTANCE = 0.06;
};
#endif