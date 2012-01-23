#include "Gestionnaire_Musiques.h"
#include "Game.h"

Gestionnaire_Musiques::Gestionnaire_Musiques() : Gestionnaire()
{
    initGestionnaire();
}

Gestionnaire_Musiques::~Gestionnaire_Musiques()
{

}

sf::Music* Gestionnaire_Musiques::get_contenu(std::string nom)
{
    return ((sf::Music*) _conteneur[nom]);
}

void Gestionnaire_Musiques::initGestionnaire()
{
    _nom = "Defaut";
    _lienFichier = FICHIER_DEFAUT;
    _lienDossier = DOSSIER_DONNEES + Game::RecupValeurLigne(_lienFichier, "[General]", "Sons");

    creerGestionnaire("[Sons]");
}

void Gestionnaire_Musiques::inserer(std::string nom)
{

}