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
    float threshold = 1.0 - 0.15;
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

void Ball::paddleCollision(Square &paddle)
{
    float paddleXPos = paddle.getLastPositionX();
    if (lastPositionX > paddleXPos - 0.07 && lastPositionX < paddleXPos + 0.07)
    {
        if (speedX == 1.25f)
        {
            speedX = 1.0f;
        }
        speedX = 0;
    }
    else if (lastPositionX > paddleXPos + 0.08 && lastPositionX < paddleXPos + 0.21)
    {
        if (speedX == 0.0f)
        {
            speedX = 1.0f;
        }
        speedX = speedX * 1.25f;
    }
    else if (lastPositionX < paddleXPos - 0.08 && lastPositionX > paddleXPos - 0.21)
    {
        if (speedX == 0.0f)
        {
            speedX = 1.0f;
        }
        speedX = -speedX * 1.25f;
    }
    speedY = -speedY;
    if (speedX > 1.5)
    {
        speedX = 1.5;
    }
    if (speedX < -1.5)
    {
        speedX = -1.5;
    }
}