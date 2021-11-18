#ifndef GAME_H
#define GAME_H

#include <SDL.h>

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
};
#endif