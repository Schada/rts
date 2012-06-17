#include "IElement.h"

IElement::IElement(sf::RenderWindow* app, float posX, float posY, int sizeX, int sizeY)
{
    _app = app;

    _sprite.SetColor(sf::Color(0, 255, 0, 128));
    _sprite.SetPosition(posX, posY);
    _sprite.SetSubRect(sf::IntRect(0, 0, sizeX, sizeY));


    if (!_font.LoadFromFile("arial.ttf", 50))
    {
        std::cerr << "La police arial.ttf est introuvable !" << std::endl;
        exit(-1);
    }

    _text.SetText("");
    _text.SetFont(_font);
    _text.SetSize(20);
}

IElement::~IElement()
{
     _app = NULL;
}

void IElement::afficher()
{
    _text.SetText(_texte);
    _app->Draw(_sprite);
    _app->Draw(_text);
}

sf::Sprite* IElement::get_sprite()
{
    return &_sprite;
}

void IElement::setTexte(std::string texte)
{
    _texte = texte;
}
