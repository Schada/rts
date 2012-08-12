/**
*   Auteur : Schada, Sept
*   Classe : Scene_MenuPrincipal
*   Role : Permet la Creation de la Scene MenuPrincipal
*/

#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include "Scene.h"
#include "../Base/constantes.h"
#include "../Interface/ZoneTexte.h"
#include <iostream>
#include <string>

class MenuPrincipal : public Scene
{
    public:
    /**
    * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
    */

    /**
    * Constructeurs et Destructeur
    */
    MenuPrincipal(sf::RenderWindow* app);
    ~MenuPrincipal();

    /**
    * Permet d'afficher la scene
    */
    void afficher();

    /**
    *   Permet de gérer les animations
    */
    void animation(std::string mess);

    /**
    * Fonctions gerant le son de la scene
    */
    float jouerSon(std::string nom);
    void jouerMusique(std::string nom);
    void stopperMusique();

    /**
    * Accesseurs
    */
    sf::Sprite* get_sprite(std::string nom);

    /**
    * Fonctions permettant d'initialiser la scene
    */
    void initGfx();
    void initSon();
    void initJeu();

    /**
    * <------------------------------------------------------- Attributs Public ------------------------------------------------------->
    */

    private:

    /**
    * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
    */
    sf::Image* _image;
    sf::Image* _imageFond;
    sf::Sprite* _fondEcran;
    sf::Sprite* _buttonPlay;
    sf::Sprite* _buttonQuit;

    sf::Sound* _sound;
    sf::SoundBuffer* _buffer;
    sf::Music* _music;

    IBloquant* _zone;

    /**
    * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
    */


};

#endif // MENUPRINCIPAL_H

