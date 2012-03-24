#include "Gestionnaire_Entites.h"
#include "../Base/Core.h"

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
    int i = 1;
    _lienDossier = Core::dossierMod + Core::RecupValeurLigne(Core::fichierMod, "[General]", "Entites");

    while(Core::RecupValeurNumeroLigne(Core::fichierMod, "[Civilisations]", i) != "[Fin]")
    {
        _lienFichier = Core::dossierMod + Core::RecupValeurLigne(Core::fichierMod, "[General]", "Civilisations") + Core::RecupValeurNumeroLigne(Core::fichierMod, "[Civilisations]", i) + ".dat";
        creerGestionnaire("[Entites]");
        i++;
    }

}

void Gestionnaire_Entites::inserer(std::string nom)
{
    Entite_Schema* entite = new Entite_Schema(_lienDossier + nom + ".dat", nom, _gi);
    _conteneur[nom] = entite;
}

