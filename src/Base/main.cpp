#include "Game.h"
#include <X11/Xlib.h>

int main()
{
    if(XInitThreads())
    {
        Game game;
        game.run();
    }
    else
    {
        std::cerr << "XInitThreads() error ..." << std::endl;
    }

    return 0;
}

