#include "Game.h"
#include <X11/Xlib.h>
<<<<<<< HEAD

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

=======
int main()
{
    XInitThreads();
    Game game;
    game.run();
>>>>>>> 71fdcbcb2eb67c2015c23ec2aaf564891ebaa76c
    return 0;
}

