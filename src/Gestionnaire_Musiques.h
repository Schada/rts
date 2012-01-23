/**
*   Auteur : Schada
*   Classe : Gestionnaire_Musiques
*   Role : Gere les sons du jeu
*/

#ifndef GESTIONNAIRE_MUSIQUES_H
#define GESTIONNAIRE_MUSIQUES_H

#include "constantes.h"
#include "Gestionnaire.h"
#include <SFML/Audio.hpp>
#include <iostream>

class Game;

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
