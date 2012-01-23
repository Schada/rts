/**
*   Auteur : Schada
*   Classe : Gestionnaire_Images
*   Role : Gere les images du jeu
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
    Gestionnaire();
    virtual ~Gestionnaire();

    std::map < std::string, void* > get_conteneur();

    virtual void initGestionnaire() = 0;
    virtual void inserer(std::string nom) = 0;

    protected:
    void creerGestionnaire(std::string balise);
    std::map < std::string, void* > _conteneur;
    std::string _nom;
    std::string _lienFichier;
    std::string _lienDossier;

};

#endif // GESTIONNAIRE_H
