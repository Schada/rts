/**
*   Auteur : Schada
*   Classe : Civilisation
*   Role : Classe des civilisations
*/

#ifndef CIVILISATION_H
#define CIVILISATION_H

#include <map>
#include <vector>
#include <string>
#include "../Gfx/Gestionnaire_Images.h"
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
    Civilisation(std::string nom, Gestionnaire_Entites* schemas);
    ~Civilisation();

    /**
    * Affiche toutes les entites de la civilisation
    */
    void afficherEntites(sf::RenderWindow* app);

    /**
    * <------------------------------------------------------- Attributs Public ------------------------------------------------------->
    */



  private:
    /**
    * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
    */

    /**
    * Nom de la civilisation
    */
    std::string _nom;

    /**
    * Pointeur sur le gestionnaire des schemas d'entites
    */
    Gestionnaire_Entites* _schemas;

    /**
    * Conteneur des entites de la civilisation
    */
    std::vector< Entite_Active* > _actives;


    /**
    * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
    */




};



#endif // CIVILISATION_H
