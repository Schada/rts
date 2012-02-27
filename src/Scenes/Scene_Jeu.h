#ifndef SCENE_JEU_H
#define SCENE_JEU_H

#include "Scene.h"


class Scene_Jeu : public Scene
{
    public:
        Scene_Jeu(sf::RenderWindow* app);
        virtual ~Scene_Jeu();

        void run();
        /**
        *   Permet de g�rer les animations du menu principal en fonction des messages pass�es en param�tres.
        */
        void animation(std::string mess);

        float jouerSon(std::string nom);
        void jouerMusique(std::string nom);
        void stopperMusique();

        sf::Sprite* get_sprite(std::string nom);

        void initGfx();
        void initSon();

    private:
        sf::Font MyFont;
        sf::String Text;
};

#endif // SCENE_JEU_H