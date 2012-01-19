#include "Engine_Event.h"

Engine_Event::Engine_Event(std::string type, std::string nom);
{
    _type = type;
    _nom = nom;
}

Engine_Event::~Engine_Event()
{

}

std::string Engine_Event::get_scene()
{
    return _scene;
}

std::string Engine_Event::get_type()
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
