#include "../engine/Game.h"

Game::Game() : isRunning(false), windowWidth(0), windowHeight(0) {}

void Game::init(int windowWidthP, int windowHeightP)
{
    windowWidth = windowWidthP;
    windowHeight = windowHeightP;
    isRunning = true;
    ball.init();
    paddle.init();
}

void Game::load()
{
    ball.load();
    paddle.load();
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
    ball.movement(dt, paddle.getLastPositionX());
    paddle.movement(dt, paddleMoveLeft, paddleMoveRight);
}

void Game::render()
{
    ball.render();
    paddle.render();
}

void Game::clean() {}