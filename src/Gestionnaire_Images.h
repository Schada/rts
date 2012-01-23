/**
*   Auteur : Schada
*   Classe : Gestionnaire_Images
*   Role : Gere les images du jeu
*/

#ifndef GESTIONNAIRE_IMAGES_H
#define GESTIONNAIRE_IMAGES_H

#include "constantes.h"
#include "Gestionnaire.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Game;

class Gestionnaire_Images : public Gestionnaire
{
    public:
    Gestionnaire_Images();
    ~Gestionnaire_Images();

    sf::Image* get_contenu(std::string nom);

    void initGestionnaire();

    void inserer(std::string nom);

};

#endif // GESTIONNAIRE_IMAGES_H
