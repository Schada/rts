#ifndef SCENE_JEU_H
#define SCENE_JEU_H

#include "Scene.h"


class Scene_Jeu : public Scene
{
    public:
        Scene_Jeu(sf::RenderWindow* app, Gestionnaire_Images* gi, Gestionnaire_Musiques* gm, Gestionnaire_Sons* gs);
        virtual ~Scene_Jeu();

        void run();
        /**
        *   Permet de gérer les animations du menu principal en fonction des messages passées en paramètres.
        */
        void animation(std::string mess);

        float jouerSon(std::string nom);
        void jouerMusique(std::string nom);
        void stopperMusique();

        sf::Sprite get_sprite(std::string nom);

    private:
};

#endif // SCENE_JEU_H
