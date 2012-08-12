#include "ITexte.h"

ITexte::ITexte(sf::RenderWindow* app, Scene* parent, std::string nom) : IElement(app, parent, nom)
{
    //ctor
}

ITexte::~ITexte()
{
    //dtor
}

std::string ITexte::type()
{
    return "TEXTE";
}

bool ITexte::verifAction(sf::Event event)
{
    return (event.MouseButton.X >= get_X1() && event.MouseButton.X <= get_X2() && event.MouseButton.Y >= get_Y1() && event.MouseButton.Y <= get_Y2());
}
