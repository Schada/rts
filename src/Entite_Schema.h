/**
*   Auteur : Schada
*   Classe :
*   Role :
*/

#ifndef ENTITE_SCHEMA_H
#define ENTITE_SCHEMA_H

#include <SFML/Graphics.hpp>

class Entite_Schema
{
  public:

    /**
    * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
    */

    /**
    * Constructeurs et Destructeur
    */
    Entite_Schema();
    ~Entite_Schema();


  private:
    /**
    * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
    */
    sf::Image* _image;

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
