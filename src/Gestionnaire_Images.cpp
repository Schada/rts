#include "Gestionnaire_Images.h"
#include "Game.h"

Gestionnaire_Images::Gestionnaire_Images() : Gestionnaire()
{
    initGestionnaire();
}

Gestionnaire_Images::~Gestionnaire_Images()
{
}

sf::Image* Gestionnaire_Images::get_contenu(std::string nom)
{

    if(existe(nom))
    {
        return ((sf::Image*) _conteneur[nom]);
    }
    return NULL;
}

void Gestionnaire_Images::initGestionnaire()
{
    _nom = "Defaut";
    _lienFichier = FICHIER_DEFAUT;
    _lienDossier = DOSSIER_DONNEES + Game::RecupValeurLigne(_lienFichier, "[General]", "Textures");

    creerGestionnaire("[Textures]");
}

void Gestionnaire_Images::inserer(std::string nom)
{
    // On creer le lien en fonction du lien du dossier des images, du nom de l'image et de l'extension .png et on charge l'image
    sf::Image image;
    std::string lien = _lienDossier + nom + ".png";
    image.LoadFromFile(lien);

    std::cout << nom << std::endl;

    // On ajoute l'image trouver dans le conteneur
    _conteneur[nom] = new sf::Image(image);
}
