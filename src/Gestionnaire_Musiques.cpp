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
    /// On creer le lien en fonction du lien du dossier des images, du nom de l'image et de l'extension .png et on charge l'image
    sf::Music music;
    std::string lien = _lienDossier + nom + ".mp3";
    music.OpenFromFile(lien);
    std::cout << nom << std::endl;

    /// On ajoute l'image trouver dans le conteneur
    _conteneur[nom] = new sf::Music(music);
}
