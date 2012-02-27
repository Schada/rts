/**
*   Auteur : Schada
*   Classe : Gestionnaire_Musiques
*   Role : Gere les musiques du jeu
*/

#ifndef GESTIONNAIRE_MUSIQUES_H
#define GESTIONNAIRE_MUSIQUES_H

#include "../Base/constantes.h"
#include "../Base/Gestionnaire.h"
#include <SFML/Audio.hpp>
#include <iostream>


class Gestionnaire_Musiques : public Gestionnaire
{
    public:
    Gestionnaire_Musiques();
    ~Gestionnaire_Musiques();

    sf::Music* get_contenu(std::string nom);

    void initGestionnaire();

    void inserer(std::string nom);

};

#endif // GESTIONNAIRE_MUSIQUES_H
