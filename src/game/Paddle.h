#ifndef PADDLE_H
#define PADDLE_H

#include <iostream>

#include "../engine/Square.h"

class Paddle : public Square
{
public:
    void init();
    void movement(float dt, bool moveLeft, bool moveRight);
    void updateScore();
    void updateLives();

    inline int getLives() { return lives; }
    inline void setLives(int livesP) { lives = livesP; }
    const float XDISTANCE = 0.21f;
    const float YDISTANCE = 0.06f;
    const float XSTARTPOS = 0.0f;
    const float YSTARTPOS = -0.85f;

private:
    float paddleScaleMatrix[16] = {
        0.4f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.1f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f};

    int score = 0;
    int lives = 5;
};
#endif