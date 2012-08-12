#include "IElement.h"
#include "../Scenes/Scene.h"

IElement::IElement(sf::RenderWindow* app, Scene* parent, std::string nom)
{
    _app = app;
    _nom = nom;
    _parent = parent;

    _texteActif = false;
    _spriteActif = false;

    if (!_font.LoadFromFile("arial.ttf", 50))
    {
        std::cerr << "La police arial.ttf est introuvable !" << std::endl;
        exit(-1);
    }

    //_sprite.SetColor(sf::Color(0,0,0,128));

    _texte.SetFont(_font);
    _texte.SetSize(20);

    _texte.SetPosition(0, 0);
    _sprite.SetPosition(0, 0);

    _action = "";

}

IElement::~IElement()
{
     _app = NULL;
     _parent = NULL;
}

void IElement::setPositionTexte(float posX, float posY)
{
    _texte.SetPosition(posX, posY);
}

void IElement::setPositionSprite(float posX, float posY)
{
    _sprite.SetPosition(posX, posY);
}

void IElement::setPositionInSprite(int posX, int posY)
{
    if(_sprite.GetImage() != NULL)
    {
        std::cout << "Set POSITION" << std::endl;
        //_sprite.SetPosition(0, 0);
        int sizeX = floor(((_sprite.GetImage())->GetWidth())/2);
        int sizeY = floor(((_sprite.GetImage())->GetHeight())/3);


        _sprite.SetSubRect(sf::IntRect(sizeX*posX, sizeY*posY, sizeX*(posX+1), sizeY*(posY+1)));
    }

}

void IElement::setColor(sf::Color color)
{
    _sprite.SetColor(color);
}

void IElement::setSize(int sizeX, int sizeY)
{
    _sprite.SetSubRect(sf::IntRect(0, 0, sizeX, sizeY));
    if(sizeX == 0 && sizeY == 0)
    {
        if(_sprite.GetImage() == NULL)
        {
            _spriteActif = false;
        }

    }
    else
    {
        _spriteActif = true;
    }

}

void IElement::setTexte(std::string texte)
{
    _texte.SetText(texte);
    if(texte == "")
    {
        _texteActif = false;
    }
    else
    {
        _texteActif = true;
    }
}

void IElement::setImage(sf::Image* image)
{
    if(image != NULL)
    {
        std::cout << "Set IMAGE" << std::endl;

        _sprite.SetImage(*image);
        image->CreateMaskFromColor(_sprite.GetPixel(0, 0));
        _spriteActif = true;
    }

}

void IElement::afficher()
{
    if(_spriteActif)
    {
        _app->Draw(_sprite);
    }
    if(_texteActif)
    {
        _app->Draw(_texte);
    }
}

sf::Sprite* IElement::get_sprite()
{
    return &_sprite;
}

std::string IElement::getNom() const
{
    return _nom;
}

void IElement::setAction(std::string action)
{
    std::cout << " Nom : " << _nom << " Nouvelle action : " << action << std::endl;
    _action = action;
}

std::string IElement::getAction() const
{
    return _action;
}



int IElement::get_X1()
{
    if(_spriteActif)
    {
        std::cout << " Nom : " << _nom << " X : " << (_sprite.GetPosition()).x << std::endl;

        return (_sprite.GetPosition()).x;
    }
    return -1;

}

int IElement::get_X2()
{
    if(_spriteActif)
    {
        int x = (_sprite.GetPosition()).x + (_sprite.GetSize()).x;
        std::cout << " Nom : " << _nom << " X : " << x << std::endl;

        return x;
    }
    return -1;

}

int IElement::get_Y1()
{
    if(_spriteActif)
    {
        std::cout << " Nom : " << _nom << " Y : " << (_sprite.GetPosition()).y << std::endl;

        return (_sprite.GetPosition()).y;
    }
    return -1;
}

int IElement::get_Y2()
{
    if(_spriteActif)
    {
        int y = (_sprite.GetPosition()).y + (_sprite.GetSize()).y;
        std::cout << " Nom : " << _nom << " Y : " << y << std::endl;

        return y;
    }
    return -1;
}
