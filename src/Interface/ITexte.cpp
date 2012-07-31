#include "ITexte.h"

ITexte::ITexte(sf::RenderWindow* app, std::string nom) : IElement(app, nom)
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
