#ifndef IELEMENT_H
#define IELEMENT_H

#include "../Base/constantes.h"

class IElement
{
    public:
        IElement(sf::RenderWindow* app, float posX, float posY, int sizeX, int sizeY);
        virtual ~IElement();

        void afficher();

        sf::Sprite* get_sprite();

        virtual void setTexte(std::string texte);

    protected:

        sf::RenderWindow* _app;
        sf::Font _font;
        sf::String _text;
        sf::Sprite _sprite;

        std::string _texte;
};

#endif
