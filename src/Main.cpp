#include "./engine/Window.h"
#include "./engine/Game.h"
#include "./engine/Timer.h"

using std::cout;
using std::endl;

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

void gameplayloop(Game game, float dt, Window &window, Timer timer)
{
    game.init(SCREEN_WIDTH, SCREEN_HEIGHT);
    game.load();
    while (game.getIsRunning())
    {
        dt = static_cast<float>(timer.computeDeltaTime()) / 1000.0f;
        game.handleInputs();
        game.update(dt);
        //Draw
        window.clearScreen();
        game.render();
        window.swapBuffer();
    }

    if (game.getIsGameOver())
    {
        cout << "The game is now over" << endl;
        cout << "To restart the game press the SPACE button" << endl;
    }

    while (game.getIsGameOver())
    {
        game.handleInputs();
        window.clearScreen();
        if (game.getIsRunning())
            gameplayloop(game, dt, window, timer);
    }
}

int main(int argc = 0, char **argv = nullptr)
{
    //Handle args
    if (argc > 0)
    {
        for (int i = 0; i < argc; ++i)
        {
            cout << argv[i] << endl;
        }
    }

    Window window = Window("Brick Breaker");
    if (!window.init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        cout << "Error has occurred during window initialization" << endl;
        return 1;
    }

    //Get info
    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *version = glGetString(GL_VERSION);
    cout << "Renderer : " << renderer << endl;
    cout << "Version : " << version << endl;

    //Initialize Game
    Game game;
    Timer timer;
    float dt;

    //Game Loop
    gameplayloop(game, dt, window, timer);

    window.clean();
    return 0;
}