#ifndef CHARGEMENT_H
#define CHARGEMENT_H

#include "Scene.h"


class Chargement : public Scene
{
    public:
        Chargement(sf::RenderWindow* app);
        virtual ~Chargement();

        void run();
        /**
        *   Permet de gérer les animations du menu principal en fonction des messages passées en paramètres.
        */
        void animation(std::string mess);

        float jouerSon(std::string nom);
        void jouerMusique(std::string nom);
        void stopperMusique();

        sf::Sprite* get_sprite(std::string nom);

        void initGfx();
        void initSon();
        void initJeu();

    private:
        sf::Clock _clock;
        sf::Font MyFont;
        sf::String Text;
};

#endif // CHARGEMENT_H
