#ifndef SCENE_JEU_H
#define SCENE_JEU_H

#include "Scene.h"
#include "../Ressources/Civilisation.h"

class Scene_Jeu : public Scene
{
    public:
        Scene_Jeu(sf::RenderWindow* app);
        virtual ~Scene_Jeu();

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
        sf::Font MyFont;
        sf::String Text;

        Gestionnaire_Entites* _schemas;
        Civilisation* _humain;
};

#endif // SCENE_JEU_H
