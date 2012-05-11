#include "Core.h"


int main()
{
    #ifdef LINUX
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
    #endif
    #ifndef LINUX
    Core core;
    core.run();
    #endif
    return 0;
}

