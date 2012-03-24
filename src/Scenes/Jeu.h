#ifndef JEU_H
#define JEU_H

#include "Scene.h"
#include "../Ressources/Civilisation.h"

class Jeu : public Scene
{
    public:
    /**
    * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
    */

    /**
    * Constructeurs et Destructeur
    */
    Jeu(sf::RenderWindow* app);
    virtual ~Jeu();

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

    sf::Font MyFont;
    sf::String Text;

    Gestionnaire_Entites* _schemas;
    Civilisation* _humain;

    /**
    * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
    */

};

#endif // JEU_H
