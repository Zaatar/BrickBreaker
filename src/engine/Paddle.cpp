#include <iostream>
#include "Paddle.h"

using std::cout;
using std::endl;

void Paddle::init()
{
    for (int i = 0; i < 16; ++i)
    {
        scaleMatrix[i] = paddleScaleMatrix[i];
    }
    translationMatrix[13] = YSTARTPOS;
    lastPositionX = XSTARTPOS;
    lastPositionY = translationMatrix[13];
    updateCoordinates(XDISTANCE, YDISTANCE);
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
        updateCoordinates(XDISTANCE, YDISTANCE);
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
        updateCoordinates(XDISTANCE, YDISTANCE);
        speedX = 1;
    }
}

void Paddle::updateScore()
{
    score += 5;
    cout << "Score is now : " << score << endl;
}

void Paddle::updateLives()
{
    lives--;
    cout << "You have " << lives << " lives left" << endl;
}