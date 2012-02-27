#ifndef SCENE_CHARGEMENT_H
#define SCENE_CHARGEMENT_H

#include "Scene.h"


class Scene_Chargement : public Scene
{
    public:
        Scene_Chargement(sf::RenderWindow* app);
        virtual ~Scene_Chargement();

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

    private:
        sf::Clock _clock;
        sf::Font MyFont;
        sf::String Text;
};

#endif // SCENE_CHARGEMENT_H
