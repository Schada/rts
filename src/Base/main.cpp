#include "Core.h"


int main()
{
    std::cout << "DEBUT" << std::endl;
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
    std::cout << "CORE" << std::endl;
    Core core;
    core.run();
    #endif
    std::cout << "FIN" << std::endl;
    return 0;
}

