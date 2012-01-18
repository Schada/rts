#include "Engine_Event.h"

Engine_Event::Engine_Event(int nb)
{
    _nb = nb;
}

Engine_Event::~Engine_Event()
{

}

int Engine_Event::get_nb()
{
    return _nb;
}
