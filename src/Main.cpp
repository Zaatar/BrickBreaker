#include "./engine/Window.h"
#include "./engine/Game.h"

using std::cout;
using std::endl;

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

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
    game.init(SCREEN_WIDTH, SCREEN_HEIGHT);
    game.load();

    //Game Loop
    while (game.getIsRunning())
    {
        game.handleInputs();
        //Draw
        window.clearScreen();
        game.render();
        window.swapBuffer();
    }
    window.clean();
    return 0;
}