/**
*   Auteur : Schada
*   Classe :
*   Role :
*/

#ifndef ENTITE_ACTIVE_H
#define ENTITE_ACTIVE_H

#include <SFML/Graphics.hpp>
#include "Entite_Schema.h"

class Entite_Active
{
  public:

    /**
    * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
    */

    /**
    * Constructeurs et Destructeur
    */
    Entite_Active(Entite_Schema* schema);
    ~Entite_Active();

    sf::Sprite* get_Sprite();


  private:
    /**
    * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
    */
    sf::Sprite _sprite;
    Entite_Schema* _schema;
    int _vie;
    int _moral;
    int _bonusvie;
    int _bonusmoral;
    int _bonusforce;
    int _bonusvitesse;
    int _bonusdefense;


    /**
    * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
    */




};



#endif // ENTITE_ACTIVE_H
