/**
*   Auteur : Schada
*   Classe : Scene (abstraite)
*   Role : Permet la Creation de Scene dans le jeu (Menu, Jeu ...)
*/

#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "Gestionnaire_Images.h"
#include "Gestionnaire_Musiques.h"
#include "Gestionnaire_Sons.h"
#include <iostream>

class Scene
{
    public:
    Scene(sf::RenderWindow* app, Gestionnaire_Images* gi, Gestionnaire_Musiques* gm, Gestionnaire_Sons* gs);
    virtual ~Scene();

    virtual void run() = 0;
    virtual void animation(std::string mess) = 0;

    virtual float jouerSon(std::string nom) = 0;
    virtual void jouerMusique(std::string nom) = 0;
    virtual void stopperMusique() = 0;

    virtual sf::Sprite get_sprite(std::string nom) = 0;

    protected:
    sf::RenderWindow* _app;
    Gestionnaire_Images* _gi;
    Gestionnaire_Sons* _gs;
    Gestionnaire_Musiques* _gm;

};

#endif // SCENE_H
