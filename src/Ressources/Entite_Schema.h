/**
*   Auteur : Schada
*   Classe :
*   Role :
*/

#ifndef ENTITE_SCHEMA_H
#define ENTITE_SCHEMA_H

#include <SFML/Graphics.hpp>
#include <string>
#include "../Gfx/Gestionnaire_Images.h"

class Entite_Schema
{
  public:

    /**
    * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
    */

    /**
    * Constructeurs et Destructeur
    */
    Entite_Schema(std::string lien, std::string nom, Gestionnaire_Images* gi);
    ~Entite_Schema();
    void creerEntite(std::string lien, Gestionnaire_Images* gi);



    /**
    * Permet de recuperer un pointeur sur l'image
    */
    sf::Image* get_Image();


  private:
    /**
    * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
    */
    sf::Image* _image;
    std::string _nom;
    std::string _description;

    int _viemax;
    int _moralmax;
    int _force;
    int _vitesse;
    int _defense;


    /**
    * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
    */




};



#endif // ENTITE_SCHEMA_H
