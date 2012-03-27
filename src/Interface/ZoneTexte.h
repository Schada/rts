#ifndef ZONETEXTE_H
#define ZONETEXTE_H

#include "../Base/constantes.h"

class Core;

class ZoneTexte
{
    public:
        ZoneTexte(sf::RenderWindow* app, float posX, float posY, int sizeX, int sizeY);
        virtual ~ZoneTexte();

        void events_ZoneTexte();
        void afficher();

        sf::Sprite* get_sprite();
    private:

        sf::RenderWindow* _app;
        sf::Font _font;
        sf::String _text;

        std::string _texte;

        sf::Sprite _sprite;

        bool _actif;

};

#endif // ZONETEXTE_H



