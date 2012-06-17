#include "Gestionnaire_Sons.h"
#include "../Base/Core.h"

Gestionnaire_Sons::Gestionnaire_Sons() : Gestionnaire()
{
    initGestionnaire();
}

Gestionnaire_Sons::~Gestionnaire_Sons()
{

}

sf::SoundBuffer* Gestionnaire_Sons::get_contenu(std::string nom)
{
    if(existe(nom))
    {
        return ((sf::SoundBuffer*) _conteneur[nom]);
    }

    return NULL;

}

void Gestionnaire_Sons::initGestionnaire()
{
    _nom = "Defaut";
    _lienFichier = Core::fichierMod;
    _lienDossier = Core::dossierMod + Core::RecupValeurLigne(_lienFichier, "[General]", "Sons") + FIN_DOSSIER;

    creerGestionnaire("[Sons]");
}

void Gestionnaire_Sons::inserer(std::string nom)
{
    sf::SoundBuffer buffer;
    std::string lien = _lienDossier + nom + ".wav";
    buffer.LoadFromFile(lien);
    std::cout << nom << std::endl;

    _conteneur[nom] = new sf::SoundBuffer (buffer);
}
