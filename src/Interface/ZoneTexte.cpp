#include "ZoneTexte.h"
#include "../Base/Core.h"

ZoneTexte::ZoneTexte(sf::RenderWindow* app, std::string nom) : IElement(app, nom)
{

}

ZoneTexte::~ZoneTexte()
{

}
void ZoneTexte::action(void* parametre)
{
    char* caract = (char*) parametre;
    modifTexte(*caract);
}

void ZoneTexte::modifTexte(char caractere)
{
    std::string texte = _texte.GetText();
    _texte.SetText(texte + caractere);
    std::cout << "Le caractere :  " << caractere << std::endl;
}
