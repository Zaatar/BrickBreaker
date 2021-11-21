#include "Ball.h"

void Ball::init()
{
    for (int i = 0; i < 16; ++i)
    {
        scaleMatrix[i] = ballScaleMatrix[i];
    }
    lastPositionX = 0.0f;
    lastPositionY = -0.9f;
}

void Ball::movement(float dt)
{
    if (abs(lastPositionX) > 1)
    {
        speedX = -speedX;
    }
    if (abs(lastPositionY) > 1)
    {
        speedY = -speedY;
    }
    translationMatrix[12] = speedX * dt + lastPositionX;
    lastPositionX = translationMatrix[12];
    translationMatrix[13] = speedY * dt + lastPositionY;
    lastPositionY = translationMatrix[13];
}