#include "../engine/Game.h"

Game::Game() : isRunning(false), windowWidth(0), windowHeight(0) {}

void Game::init(int windowWidthP, int windowHeightP)
{
    windowWidth = windowWidthP;
    windowHeight = windowHeightP;
    isRunning = true;
    ball.init();
}

void Game::load()
{
    ball.load();
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
            break;
        default:
            break;
        }
    }
}

void Game::update(float dt)
{
    ball.movement(dt);
}

void Game::render()
{
    ball.render();
}

void Game::clean() {}