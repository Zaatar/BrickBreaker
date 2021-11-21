#ifndef BALL_H
#define BALL_H

#include <math.h>
#include "Square.h"

class Ball : public Square
{
public:
    Ball() = default;
    ~Ball() = default;

    void init();
    void movement(float dt);

private:
    float ballScaleMatrix[16] = {
        0.1f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.1f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.1f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f};
};
#endif