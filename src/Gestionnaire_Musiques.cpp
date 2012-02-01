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
    if(existe(nom))
    {
        return ((sf::Music*) _conteneur[nom]);
    }

    return NULL;
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
    sf::Music music;
    std::string lien = _lienDossier + nom + ".mp3";
    music.OpenFromFile(lien);
    std::cout << nom << std::endl;

    _conteneur[nom] = new sf::Music(music);
}
