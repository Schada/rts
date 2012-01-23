#ifndef SCENE_JEU_H
#define SCENE_JEU_H

#include "Scene.h"


class Scene_Jeu : public Scene
{
    public:
        Scene_Jeu(Gestionnaire_Images* gi);
        virtual ~Scene_Jeu();

        void run(sf::RenderWindow* app);
        /**
        *   Permet de gérer les animations du menu principal en fonction des messages passées en paramètres.
        */
        void animation(sf::RenderWindow* app, std::string mess);
    private:
        Gestionnaire_Images _gi();
};

#endif // SCENE_JEU_H
