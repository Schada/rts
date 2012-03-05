#include "Engine_Event.h"

Engine_Event::Engine_Event(int scene, int type, std::string nom, sf::Event* event)
{
    _scene = scene;
    _type = type;
    _nom = nom;
    _event = event;
}

Engine_Event::~Engine_Event()
{
    if(_event != NULL)
    {
        delete _event;
    }
}

void Engine_Event::changerEvent(int scene, int type, std::string nom, sf::Event* event)
{
    _scene = scene;
    _type = type;
    _nom = nom;
    _event = event;
}

int Engine_Event::get_scene()
{
    return _scene;
}

int Engine_Event::get_type()
{
    return _type;
}

std::string Engine_Event::get_nom()
{
    return _nom;
}

sf::Event* Engine_Event::get_event()
{
    return _event;
}
