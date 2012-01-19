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
        sf::Image image;
        sf::Sprite buttonPlay;
        sf::Sprite buttonQuit;
};

#endif // SCENE_MENUPRINCIPAL_H
