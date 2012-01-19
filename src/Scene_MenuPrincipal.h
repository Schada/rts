/**
*   Auteur : Schada
*   Classe : Scene_MenuPrincipal
*   Role : Permet la Creation de la Scene MenuPrincipal
*/

#ifndef SCENE_MENUPRINCIPAL_H
#define SCENE_MENUPRINCIPAL_H

#include "Scene.h"
#include "constantes.h"
#include <iostream>
#include <string>

class Scene_MenuPrincipal : public Scene
{
    public:
        Scene_MenuPrincipal(Gestionnaire_Images* gi, sf::RenderWindow* app);
        void run(sf::RenderWindow* app);
<<<<<<< HEAD
        /**
        *   Permet de gérer les animations du menu principal en fonction des messages passées en paramètres.
        */
        void animation(sf::RenderWindow* app, std::string mess);
=======
>>>>>>> 4472fdee08d0b82b3f163df669252a33055c8117
        sf::Image image;
        sf::Sprite buttonPlay;
        sf::Sprite buttonQuit;
};

#endif // SCENE_MENUPRINCIPAL_H

