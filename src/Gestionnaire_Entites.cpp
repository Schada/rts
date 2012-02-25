#include "Gestionnaire_Entites.h"
#include "Game.h"

Gestionnaire_Entites::Gestionnaire_Entites(std::string nom, Gestionnaire_Images* gi) : Gestionnaire()
{
    _nom = nom;
    _gi = gi;
    initGestionnaire();
}

Gestionnaire_Entites::~Gestionnaire_Entites()
{

}

Entite_Schema* Gestionnaire_Entites::get_contenu(std::string nom)
{
    if(existe(nom))
    {
        return ((Entite_Schema*) _conteneur[nom]);
    }

    return NULL;
}

void Gestionnaire_Entites::initGestionnaire()
{
    _lienDossier = DOSSIER_DONNEES + Game::RecupValeurLigne(FICHIER_DEFAUT, "[Civilisations]", _nom);
    _lienFichier = _lienDossier + FICHIER_CIV_DEFAUT;
    creerGestionnaire("[Entites]");
}

void Gestionnaire_Entites::inserer(std::string nom)
{
    Entite_Schema* entite = new Entite_Schema(_lienDossier + nom + ".txt", nom, _gi);
    _conteneur[nom] = entite;
}

