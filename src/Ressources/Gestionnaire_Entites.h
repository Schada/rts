/**
*   Auteur : Schada
*   Classe : Gestionnaire_Entites
*   Role : Gere les schemas des entites du jeu
*/

#ifndef GESTIONNAIRE_ENTITES_H
#define GESTIONNAIRE_ENTITES_H

#include "../Base/constantes.h"
#include "../Base/Gestionnaire.h"
#include <SFML/Audio.hpp>
#include <iostream>
#include "Entite_Schema.h"

class Core;

class Gestionnaire_Entites : public Gestionnaire
{
    public:
    Gestionnaire_Entites(std::string nom, Gestionnaire_Images* gi);
    ~Gestionnaire_Entites();

    Entite_Schema* get_contenu(std::string nom);

    void initGestionnaire();

    void inserer(std::string nom);

    private:
        Gestionnaire_Images* _gi;

};

#endif // GESTIONNAIRE_ENTITES_H

