#include "ZoneTexte.h"
#include "../Base/Core.h"

ZoneTexte::ZoneTexte(sf::RenderWindow* app, float posX, float posY, int sizeX, int sizeY) : IEBloquant(app, posX, posY, sizeX, sizeY)
{

}

ZoneTexte::~ZoneTexte()
{

}

void ZoneTexte::modifTexte(char caractere)
{
    _texte += caractere;
    std::cout << "Le caractere :  " << caractere << std::endl;
}
