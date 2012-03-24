/**
*   Auteur : Sept64
*   Classe : Options
*   Role : Permet la Creation de la scene options dans le jeu
*/

#ifndef OPTIONS_H
#define OPTIONS_H

#include <SFML/Graphics.hpp>
#include "../Gfx/Gestionnaire_Images.h"
#include "../Son/Gestionnaire_Musiques.h"
#include "../Son/Gestionnaire_Sons.h"
#include <iostream>
#include "Scene.h"

class Options : public Scene
{
    public:
    /**
    * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
    */

    /**
    * Constructeurs et Destructeur
    */
    Options(sf::RenderWindow* app);
    virtual ~Options();

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
    sf::Sprite* _buttonPleinEcran;
    sf::Sprite* _buttonReturn;

    sf::Sound* _sound;
    sf::SoundBuffer* _buffer;
    sf::Music* _music;

    /**
    * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
    */

};

#endif // OPTIONS_H
