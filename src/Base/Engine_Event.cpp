#include "Engine_Event.h"

Engine_Event::Engine_Event(int scene, int type, std::string nom, sf::Event* event)
{
    _scene = scene;
    _type = type;
    _nom = nom;
    if(event)
    {
        _event = new sf::Event(*event);
    }
    else
    {
        _event = NULL;
    }
}

Engine_Event::Engine_Event(Engine_Event const& engine_event)
{
    _scene = engine_event._scene;
    _type = engine_event._type;
    _nom = engine_event._nom;

    if(engine_event._event)
    {
        _event = new sf::Event(*engine_event._event);
    }
    else
    {
        _event = NULL;
    }
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
    if(_event)
    {
        delete _event;
    }

    if(event)
    {
        _event = new sf::Event(*event);
    }
    else
    {
        _event = NULL;
    }
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
