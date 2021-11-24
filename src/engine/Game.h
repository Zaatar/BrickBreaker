#ifndef GAME_H
#define GAME_H

#include <set>
#include <vector>
#include <SDL.h>

#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

using std::set;
using std::vector;

class Game
{
public:
    Game();
    ~Game() = default;

    void init(int windowWidth, int windowHeight);
    void load();
    void handleInputs();
    void update(float dt);
    void render();
    void clean();
    void updateScore();

    inline bool getIsRunning() { return isRunning; }

private:
    bool isRunning;
    int windowWidth, windowHeight;

    Ball ball;
    Paddle paddle;

    bool paddleMoveLeft = false;
    bool paddleMoveRight = false;
    bool collision = false;

    Brick brickArray[30];
    vector<Brick> bricksVector;
    set<Brick> brickSet;
    float xStartPos = -0.9f;
    float yStartPos = 0.9f;
    const int COLUMNS = 5;
    const int ROWS = 5;
    const float BRICK_GAP = 0.2f;
};
#endif