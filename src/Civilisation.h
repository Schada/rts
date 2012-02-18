/**
*   Auteur : Schada
*   Classe :
*   Role :
*/

#ifndef CIVILISATION_H
#define CIVILISATION_H

#include <map>
#include <vector>
#include <string>
#include "Entite_Schema.h"
#include "Entite_Active.h"

class Civilisation
{
  public:

    /**
    * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
    */

    /**
    * Constructeurs et Destructeur
    */
    Civilisation();
    ~Civilisation();


  private:
    /**
    * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
    */
    std::string _nom;
    std::map<std::string, Entite_Schema*> _schemas;
    std::vector<Entite_Active*> _actives;


    /**
    * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
    */




};



#endif // CIVILISATION_H
