/**
*   Auteur : Schada
*   Classe : Gestionnaire_Sons
*   Role : Gere les sons du jeu
*/

#ifndef GESTIONNAIRE_SONS_H
#define GESTIONNAIRE_SONS_H

#include "constantes.h"
#include "Gestionnaire.h"
#include <SFML/Audio.hpp>
#include <iostream>


class Gestionnaire_Sons : public Gestionnaire
{
    public:
        Gestionnaire_Sons();
        ~Gestionnaire_Sons();
        sf::SoundBuffer* get_contenu(std::string nom);
        void initGestionnaire();
        void inserer(std::string nom);
};

#endif // GESTIONNAIRE_SONS_H
