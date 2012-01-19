/**
*   Auteur : Schada
*   Classe : Scene (abstraite)
*   Role : Permet la Creation de Scene dans le jeu (Menu, Jeu ...)
*/

#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "Gestionnaire_Images.h"
#include <iostream>

class Scene
{
    public:
    Scene(Gestionnaire_Images* gi);
    virtual ~Scene();
<<<<<<< HEAD
    virtual void run(sf::RenderWindow* app) = 0;
    virtual void animation(sf::RenderWindow* app, std::string mess) = 0;
=======
    virtual void run(sf::RenderWindow* app);

>>>>>>> 4472fdee08d0b82b3f163df669252a33055c8117
    private:
    Gestionnaire_Images* _gi;

};

#endif // SCENE_H
