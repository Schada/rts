#include "IEBloquant.h"

IEBloquant::IEBloquant(sf::RenderWindow* app, float posX, float posY, int sizeX, int sizeY) : IElement(_app, posX, posY, sizeX, sizeY)
{

}

IEBloquant::~IEBloquant()
{

}

void IEBloquant::setActif(bool actif)
{
    _actif = actif;
}

bool IEBloquant::getActif() const
{
    return _actif;
}
