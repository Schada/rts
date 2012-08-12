#include "ZoneTexte.h"

ZoneTexte::ZoneTexte(sf::RenderWindow* app, Scene* parent, std::string nom) : IBloquant(app, parent, nom)
{
    _stock = "";
}

ZoneTexte::~ZoneTexte()
{

}

void ZoneTexte::action(sf::Event event)
{
    modifTexte(event);
}

void ZoneTexte::modifTexte(sf::Event event)
{
    char caractere = event.Text.Unicode;
    std::string texte = _texte.GetText();
    if(event.Text.Unicode != sf::Key::Back)
    {
        if(event.Text.Unicode > 30 && event.Text.Unicode < 127 )
        {
            _texte.SetText(texte + caractere);
            std::cout << "Le caractere :  " << caractere << std::endl;
        }
        else if(event.Text.Unicode == sf::Key::Space)
        {
            _texte.SetText(texte + ' ');
        }
        else if(event.Text.Unicode == sf::Key::Return)
        {
            if(event.Key.Shift == true)
            {
                _texte.SetText(texte + '\n');
            }
            else
            {
                _texte.SetText("");
                _stock = texte;
            }
        }
        else if(event.Key.Code == sf::Key::Up)
        {
            _texte.SetText(_stock);
        }
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

std::string ZoneTexte::getStock() const
{
    return _stock;
}
