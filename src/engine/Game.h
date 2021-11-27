#ifndef GAME_H
#define GAME_H

#include <set>
#include <vector>
#include <SDL.h>

#include "../game/Ball.h"
#include "../game/Paddle.h"
#include "../game/Brick.h"

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
    void populateBricks();
    void loadBricks();
    void renderBricks();
    void restartBricks();

    inline bool getIsRunning() { return isRunning; }
    inline bool getIsGameOver() { return isGameOver; }

private:
    bool isRunning;
    bool isGameOver = false;
    int windowWidth, windowHeight;

    Ball ball;
    Paddle paddle;

    bool paddleMoveLeft = false;
    bool paddleMoveRight = false;
    bool paddleCollision = false;
    bool brickCollision = false;

    vector<Brick> bricksVector;
    float origXStartPos = -0.9f;
    float origYStartPos = 0.9f;
    float xStartPos = -0.9f;
    float yStartPos = 0.9f;
    const int COLUMNS = 6;
    const int ROWS = 8;
    const float Y_BRICK_GAP = 0.15f;
    const float BRICK_GAP = 0.25f;
};
#endif