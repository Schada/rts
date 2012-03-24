/**
*   Auteur : Schada
*   Classe : Gestionnaire
*   Role : Classe abstraite des Gestionnaires
*/

#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include "constantes.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>

class Gestionnaire
{
    public:
    /**
    * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
    */

    /**
    * Constructeurs et Destructeur
    */
    Gestionnaire();
    virtual ~Gestionnaire();

    /**
    * Accesseurs
    */
    std::map < std::string, void* > get_conteneur();


    /**
    * Doit initialiser les variables pour proceder a la creation du gestionnaire
    */
    virtual void initGestionnaire() = 0;

    /**
    * Permet d'inserer un element au gestionnaire
    */
    virtual void inserer(std::string nom) = 0;

    /**
    * <------------------------------------------------------- Attributs Public ------------------------------------------------------->
    */

    protected:

    /**
    * <------------------------------------------------------- Attributs Protected ------------------------------------------------------->
    */

    std::map < std::string, void* > _conteneur;
    std::string _nom;
    std::string _lienFichier;
    std::string _lienDossier;

    /**
    * <------------------------------------------------------- Methodes Protected ------------------------------------------------------->
    */

    /**
    * Creer le gestionnaire avec les parametres indiquer lors de l'initilisation
    */
    void creerGestionnaire(std::string balise);

    /**
    * Permet de savoir si un element existe dans le gestionnaire
    */
    bool existe(std::string nom);

};

#endif // GESTIONNAIRE_H
