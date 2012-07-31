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
#include "../Interface/IElement.h"
#include "../Interface/ITexte.h"
#include <iostream>

class Core;

class Scene
{
    public:
    /**
    * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
    */

    /**
    * Constructeurs et Destructeur
    */
    Scene(sf::RenderWindow* app, std::string nom, std::string fond);
    virtual ~Scene();

    /**
    * Permet d'afficher la scene
    */
    virtual void afficher();



    /**
    *   Permet de gérer les animations
    */
    //virtual void animation(std::string mess) = 0;

    /**
    * Fonctions gerant le son de la scene
    */
    //virtual float jouerSon(std::string nom) = 0;
    //virtual void jouerMusique(std::string nom) = 0;
    //virtual void stopperMusique() = 0;

    /**
    * Accesseurs
    */
    //virtual sf::Sprite* get_sprite(std::string nom) = 0;


    /**
    * Setters
    */
    void set_gi(Gestionnaire_Images* gi);
    void set_gm(Gestionnaire_Musiques* gm);
    void set_gs(Gestionnaire_Sons* gs);

    /**
    * Fonctions permettant d'initialiser la scene
    */
    virtual void initGfx();
    virtual void initSon();
    virtual void initJeu();

    /**
    * Permet de savoir si la scene est initialiser
    */
    bool isInit();

    /**
    * Renvoit le nombre de milisecondes ecoulees depuis la creation de la scene
    */
    float time();


    bool existeElement(std::string nom);

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

    sf::Sprite* _fond;

    std::string _nom;

    std::vector < IElement* > _elements;

    std::string _nomFond;
    std::string _fichier;

    /**
    * <------------------------------------------------------- Methodes Protected ------------------------------------------------------->
    */

    void initInterface();

};

#endif // SCENE_H
