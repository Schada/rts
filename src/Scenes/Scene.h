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
    /**
    * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
    */

    /**
    * Constructeurs et Destructeur
    */
    Scene(sf::RenderWindow* app);
    virtual ~Scene();

    /**
    * Permet d'afficher la scene
    */
    virtual void afficher() = 0;

    /**
    *   Permet de gérer les animations
    */
    virtual void animation(std::string mess) = 0;

    /**
    * Fonctions gerant le son de la scene
    */
    virtual float jouerSon(std::string nom) = 0;
    virtual void jouerMusique(std::string nom) = 0;
    virtual void stopperMusique() = 0;

    /**
    * Accesseurs
    */
    virtual sf::Sprite* get_sprite(std::string nom) = 0;

    /**
    * Setters
    */
    void set_gi(Gestionnaire_Images* gi);
    void set_gm(Gestionnaire_Musiques* gm);
    void set_gs(Gestionnaire_Sons* gs);

    /**
    * Fonctions permettant d'initialiser la scene
    */
    virtual void initGfx() = 0;
    virtual void initSon() = 0;
    virtual void initJeu() = 0;

    /**
    * Permet de savoir si la scene est initialiser
    */
    bool isInit();

    /**
    * Renvoit le nombre de milisecondes ecoulees depuis la creation de la scene
    */
    float time();

    /**
    * <------------------------------------------------------- Attributs Public ------------------------------------------------------->
    */

    protected:

    /**
    * <------------------------------------------------------- Attributs Protected ------------------------------------------------------->
    */

    sf::RenderWindow* _app;
    Gestionnaire_Images* _gi;
    Gestionnaire_Sons* _gs;
    Gestionnaire_Musiques* _gm;

    bool _gfxInit;
    bool _sonInit;
    bool _jeuInit;

    sf::Clock _clock;

    /**
    * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
    */

};

#endif // SCENE_H
