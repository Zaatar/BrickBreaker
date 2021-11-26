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
    setX(lastPositionX);
    setY(lastPositionY);
    updateCoordinates(XDISTANCE, YDISTANCE);
    for (int i = 0; i < 3; ++i)
    {
        colors[i] = 1.0f;
    }
}

void Ball::movement(float dt, Paddle &paddle)
{
    float threshold = 1.0 - 0.15;
    float paddleXPosition = paddle.getLastPositionX();
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
            paddle.updateLives();
        }
        if (lastPositionX > paddleXPosition + 0.2)
        {
            cout << "Ball hits to the right of the paddle" << endl;
            lastPositionX = XSTARTPOS;
            lastPositionY = YSTARTPOS;
            speedX = 1.0f;
            speedY = 1.0f;
            paddle.updateLives();
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
    float xValue = speedX * dt + lastPositionX;
    setX(xValue);
    lastPositionX = getX();
    float yValue = speedY * dt + lastPositionY;
    setY(yValue);
    lastPositionY = getY();
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

void Ball::brickCollision(Square &brick)
{
    speedY = -speedY;
}