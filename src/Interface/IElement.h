#ifndef IELEMENT_H
#define IELEMENT_H

#include "../Base/constantes.h"

class Scene;

class IElement
{
    public:
        IElement(sf::RenderWindow* app, Scene* parent, std::string nom);
        virtual ~IElement();

        void setPositionTexte(float posX, float posY);
        void setPositionSprite(float posX, float posY);
        void setPositionInSprite(int posX, int posY);
        void setColor(sf::Color color);
        void setSize(int sizeX, int sizeY);

        void afficher();
        virtual std::string type() = 0;

        sf::Sprite* get_sprite();

        virtual void setTexte(std::string texte);
        void setImage(sf::Image* image);

        std::string getNom() const;

        void setAction(std::string action);
        std::string getAction() const;
        virtual bool verifAction(sf::Event event) = 0;

        int get_X1();
        int get_X2();
        int get_Y1();
        int get_Y2();


    protected:

        sf::RenderWindow* _app;
        Scene* _parent;
        std::string _nom;
        sf::Font _font;
        sf::String _texte;
        sf::Sprite _sprite;

        bool _texteActif;
        bool _spriteActif;

        std::string _type;
        std::string _action;
};

#endif
