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
    std::string valeur;
    Struct_File sfile;
    sfile.nom = Core::fichierMod;
    (sfile.fichier).open((sfile.nom).c_str(), std::ios::in);

    if(sfile.fichier)
    {
        std::string dossier_civ = Core::RecupValeurLigne(Core::fichierMod, "[General]", "Civilisations");
        _lienDossier = Core::dossierMod + Core::RecupValeurLigne(Core::fichierMod, "[General]", "Entites") + FIN_DOSSIER;


        if(Core::DeplacementFichier(&sfile, "[Civilisations]"))
        {
            getline(sfile.fichier, valeur);
            while((!sfile.fichier.eof()) && (valeur != "[Fin]"))
            {
                _lienFichier = Core::dossierMod + dossier_civ + FIN_DOSSIER + valeur + ".dat";
                creerGestionnaire("[Entites]");
                getline(sfile.fichier, valeur);
            }
        }

        (sfile.fichier).close();
    }
    else
    {
        std::cerr << "Le fichier " << sfile.nom << " est introuvable." << std::endl;
    }


}

void Gestionnaire_Entites::inserer(std::string nom)
{
    Entite_Schema* entite = new Entite_Schema(_lienDossier + nom + ".dat", nom, _gi);
    _conteneur[nom] = entite;
}

