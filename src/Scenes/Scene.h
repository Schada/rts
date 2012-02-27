/**
*   Auteur : Schada
*   Classe : Scene (abstraite)
*   Role : Permet la Creation de Scene dans le jeu (Menu, Jeu ...)
*/

#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "../Gfx/Gestionnaire_Images.h"
#include "../Son/Gestionnaire_Musiques.h"
#include "../Son/Gestionnaire_Sons.h"
#include <iostream>

class Scene
{
    public:
    Scene(sf::RenderWindow* app);
    virtual ~Scene();

    virtual void run() = 0;
    virtual void animation(std::string mess) = 0;

    virtual float jouerSon(std::string nom) = 0;
    virtual void jouerMusique(std::string nom) = 0;
    virtual void stopperMusique() = 0;

    virtual sf::Sprite* get_sprite(std::string nom) = 0;

    void set_gi(Gestionnaire_Images* gi);
    void set_gm(Gestionnaire_Musiques* gm);
    void set_gs(Gestionnaire_Sons* gs);

    virtual void initGfx() = 0;
    virtual void initSon() = 0;
    bool isInit();

    float time();

    protected:
    sf::RenderWindow* _app;
    Gestionnaire_Images* _gi;
    Gestionnaire_Sons* _gs;
    Gestionnaire_Musiques* _gm;

    bool _gfxInit;
    bool _sonInit;

    sf::Clock _clock;

};

#endif // SCENE_H
