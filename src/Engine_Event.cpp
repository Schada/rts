#include "Engine_Event.h"

Engine_Event::Engine_Event(std::string nb)
{
    _nb = nb;
}

Engine_Event::~Engine_Event()
{

}

std::string Engine_Event::get_nb()
{
    return _nb;
}
