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
#include "Gestionnaire_Images.h"
#include "Gestionnaire_Entites.h"
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
    Civilisation(std::string nom, Gestionnaire_Images* gi);
    ~Civilisation();



  private:
    /**
    * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
    */
    std::string _nom;
    Gestionnaire_Entites* _schemas;
    std::vector<Entite_Active*> _actives;


    /**
    * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
    */




};



#endif // CIVILISATION_H
