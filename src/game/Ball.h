#ifndef BALL_H
#define BALL_H

#include <math.h>
#include "Paddle.h"

class Ball : public Square
{
public:
    Ball() = default;
    ~Ball() = default;

    void init();
    void movement(float dt, Paddle &paddle);
    void paddleCollision(Square &paddle);
    void brickCollision(Square &brick);

    const float XDISTANCE = 0.06;
    const float YDISTANCE = 0.06;
    const float YSTARTPOS = -0.7f;
    const float XSTARTPOS = 0.0f;

private:
    float ballScaleMatrix[16] = {
        0.1f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.1f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.1f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f};
};
#endif