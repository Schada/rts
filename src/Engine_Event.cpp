#include "Engine_Event.h"

Engine_Event::Engine_Event(int scene, int type, std::string nom, std::string parametre)
{
    _scene = scene;
    _type = type;
    _nom = nom;
    _parametre = parametre;
}

Engine_Event::~Engine_Event()
{

}

void Engine_Event::changerEvent(int scene, int type, std::string nom, std::string parametre)
{
    _scene = scene;
    _type = type;
    _nom = nom;
    _parametre = parametre;
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

std::string Engine_Event::get_parametre()
{
    return _parametre;
}
