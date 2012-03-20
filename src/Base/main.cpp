#include "Game.h"
#include <X11/Xlib.h>
int main()
{
    XInitThreads();
    Game game;
    game.run();
    return 0;
}
