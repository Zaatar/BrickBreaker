#include <iostream>
#include "Ball.h"

using std::cout;
using std::endl;

void Ball::init()
{
    for (int i = 0; i < 16; ++i)
    {
        scaleMatrix[i] = ballScaleMatrix[i];
    }
    lastPositionX = 0.0f;
    lastPositionY = -0.7f;
    translationMatrix[12] = lastPositionX;
    translationMatrix[13] = lastPositionY;
    updateCoordinates(XDISTANCE, YDISTANCE);
}

void Ball::movement(float dt, float paddleXPosition)
{
    float threshold = 1.0 - 0.05;
    if (lastPositionY < -threshold)
    {
        //Ball hits to the left of the paddle
        if (lastPositionX < paddleXPosition - 0.2)
        {
            cout << "Ball hits to the left of the paddle" << endl;
            lastPositionX = XSTARTPOS;
            lastPositionY = YSTARTPOS;
            speedX = 1.0f;
            speedY = 1.0f;
        }
        if (lastPositionX > paddleXPosition + 0.2)
        {
            cout << "Ball hits to the right of the paddle" << endl;
            lastPositionX = XSTARTPOS;
            lastPositionY = YSTARTPOS;
            speedX = 1.0f;
            speedY = 1.0f;
        }
    }
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
    updateCoordinates(XDISTANCE, YDISTANCE);
}