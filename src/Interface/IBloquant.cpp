#include "IBloquant.h"
#include "../Base/Core.h"

IBloquant::IBloquant(sf::RenderWindow* app, Scene* parent, std::string nom) : IElement(app, parent, nom)
{
    //ctor
}

IBloquant::~IBloquant()
{
    //dtor
}

bool IBloquant::verifAction(sf::Event event)
{
    if(event.MouseButton.X >= get_X1() && event.MouseButton.X <= get_X2() && event.MouseButton.Y >= get_Y1() && event.MouseButton.Y <= get_Y2())
    {
        _parent->setActif(this);
    }
    else
    {
        _parent->setActif(NULL);
    }
    return false;
}
