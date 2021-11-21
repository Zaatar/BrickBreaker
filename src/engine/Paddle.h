#ifndef PADDLE_H
#define PADDLE_H

#include "Square.h"

class Paddle : public Square
{
public:
    void init();
    void movement(float dt, bool moveLeft, bool moveRight);

private:
    float paddleScaleMatrix[16] = {
        0.4f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.1f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f};
};
#endif