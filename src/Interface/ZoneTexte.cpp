#include "ZoneTexte.h"

ZoneTexte::ZoneTexte(sf::RenderWindow* app, Scene* parent, std::string nom) : IBloquant(app, parent, nom)
{

}

ZoneTexte::~ZoneTexte()
{

}

void ZoneTexte::action(sf::Event event)
{
    modifTexte(event.Text.Unicode);
}

void ZoneTexte::modifTexte(char caractere)
{
    std::string texte = _texte.GetText();
    if(caractere != sf::Key::Return)
    {
        _texte.SetText(texte + caractere);
        std::cout << "Le caractere :  " << caractere << std::endl;
    }
    else
    {
        _texte.SetText(texte.substr(0,texte.size() -1));
    }

}

std::string ZoneTexte::type()
{
    return "ZONETEXTE";
}

void ZoneTexte::afficherActif()
{

}

bool ZoneTexte::verifActif(sf::Event event)
{
    return (event.MouseButton.X >= get_X1() && event.MouseButton.X <= get_X2() && event.MouseButton.Y >= get_Y1() && event.MouseButton.Y <= get_Y2());
}
