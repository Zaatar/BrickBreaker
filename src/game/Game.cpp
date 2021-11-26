#include <iostream>
#include "../engine/Game.h"

using std::cout;
using std::endl;

Game::Game() : isRunning(false), windowWidth(0), windowHeight(0) {}

void Game::populateBricks()
{
    bricksVector.reserve(ROWS * COLUMNS);
    for (int i = 0; i < COLUMNS; ++i)
    {
        for (int j = 0; j < ROWS; ++j)
        {
            Brick brick = Brick();
            brick.init(xStartPos, yStartPos);
            bricksVector.push_back(brick);
            xStartPos = xStartPos + BRICK_GAP;
        }
        xStartPos = origXStartPos;
        yStartPos = yStartPos - Y_BRICK_GAP;
    }
}

void Game::loadBricks()
{
    for (int i = 0; i < bricksVector.size(); ++i)
    {
        bricksVector[i].load();
    }
}

void Game::renderBricks()
{
    for (int i = 0; i < bricksVector.size(); ++i)
    {
        bricksVector[i].render();
    }
}

void Game::restartBricks()
{
    xStartPos = origXStartPos;
    yStartPos = origYStartPos;
    populateBricks();
    loadBricks();
    renderBricks();
}

void Game::init(int windowWidthP, int windowHeightP)
{
    windowWidth = windowWidthP;
    windowHeight = windowHeightP;
    isRunning = true;
    ball.init();
    paddle.init();
    populateBricks();
}

void Game::load()
{
    ball.load();
    paddle.load();
    loadBricks();
}

void Game::handleInputs()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
            if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)
            {
                paddleMoveRight = true;
                paddleMoveLeft = false;
            }
            if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_q)
            {
                paddleMoveRight = false;
                paddleMoveLeft = true;
            }
            break;
        case SDL_KEYUP:
            if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)
            {
                paddleMoveRight = false;
            }
            if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_q)
            {
                paddleMoveLeft = false;
            }
        default:
            break;
        }
    }
}

void Game::update(float dt)
{
    ball.movement(dt, paddle);
    paddle.movement(dt, paddleMoveLeft, paddleMoveRight);
    //To be improved upon, having to call the paddleCollision from paddle is not the best
    //Paddle Collision Code
    paddleCollision = ball.checkCollision(ball, paddle);
    if (paddleCollision)
    {
        ball.paddleCollision(paddle);
    }
    //Brick Collision Code
    for (int i = 0; i < bricksVector.size(); i++)
    {
        brickCollision = ball.checkCollision(ball, bricksVector[i]);
        if (brickCollision)
        {
            ball.brickCollision(bricksVector[i]);
            bricksVector.erase(bricksVector.begin() + i);
            paddle.updateScore();
        }
        brickCollision = false;
    }
    //Brick Restart Code
    if (bricksVector.empty())
    {
        restartBricks();
    }
}

void Game::render()
{
    ball.render();
    paddle.render();
    renderBricks();
}

void Game::clean() {}