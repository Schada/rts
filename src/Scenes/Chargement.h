#ifndef CHARGEMENT_H
#define CHARGEMENT_H

#include "Scene.h"


class Chargement : public Scene
{
    public:
    /**
    * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
    */

    /**
    * Constructeurs et Destructeur
    */
    Chargement(sf::RenderWindow* app);
    virtual ~Chargement();

    /**
    * Permet d'afficher la scene
    */
    void afficher();

    /**
    *   Permet de gérer les animations du menu principal en fonction des messages passées en paramètres.
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

    sf::Font MyFont;
    sf::String Text;

    /**
    * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
    */
};

#endif // CHARGEMENT_H
