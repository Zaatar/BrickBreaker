#include "Paddle.h"

void Paddle::init()
{
    for (int i = 0; i < 16; ++i)
    {
        scaleMatrix[i] = paddleScaleMatrix[i];
    }
    translationMatrix[13] = -0.95;
    lastPositionX = 0.0f;
}

void Paddle::movement(float dt, bool moveLeft, bool moveRight)
{
    float threshold = 1.0f - 0.2f;
    if (moveLeft == true)
    {
        if (lastPositionX < -threshold)
        {
            speedX = 0;
        }
        translationMatrix[12] = -speedX * dt + lastPositionX;
        lastPositionX = translationMatrix[12];
        speedX = 1;
    }
    if (moveRight == true)
    {
        if (lastPositionX > threshold)
        {
            speedX = 0;
        }
        translationMatrix[12] = speedX * dt + lastPositionX;
        lastPositionX = translationMatrix[12];
        speedX = 1;
    }
}