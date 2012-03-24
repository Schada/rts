#include "Core.h"
#include <X11/Xlib.h>

int main()
{
    if(XInitThreads())
    {
        Core core;
        core.run();
    }
    else
    {
        std::cerr << "XInitThreads() error ..." << std::endl;
        return -1;
    }

    return 0;
}

