#include "Gestionnaire_Sons.h"
#include "Game.h"

Gestionnaire_Sons::Gestionnaire_Sons() : Gestionnaire()
{
    initGestionnaire();
}

Gestionnaire_Sons::~Gestionnaire_Sons()
{

}

sf::SoundBuffer* Gestionnaire_Sons::get_contenu(std::string nom)
{
    return ((sf::SoundBuffer*) _conteneur[nom]);
}

void Gestionnaire_Sons::initGestionnaire()
{
    _nom = "Defaut";
    _lienFichier = FICHIER_DEFAUT;
    _lienDossier = DOSSIER_DONNEES + Game::RecupValeurLigne(_lienFichier, "[General]", "Sons");

    creerGestionnaire("[Sons]");
}

void Gestionnaire_Sons::inserer(std::string nom)
{

}
