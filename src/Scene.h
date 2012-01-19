/**
*   Auteur : Schada
*   Classe : Scene (abstraite)
*   Role : Permet la Creation de Scene dans le jeu (Menu, Jeu ...)
*/

#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "Gestionnaire_Images.h"

class Scene
{
    public:
    Scene(Gestionnaire_Images* gi);
    virtual ~Scene();
    virtual void run(sf::RenderWindow* app) = 0;
    virtual void animation(sf::RenderWindow* app, std::string mess) = 0;
    private:
    Gestionnaire_Images* _gi;

};

#endif // SCENE_H
