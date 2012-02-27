#include "Entite_Schema.h"

Entite_Schema::Entite_Schema(std::string lien, std::string nom, Gestionnaire_Images* gi)
{
    _nom = nom;
    creerEntite(lien, gi);
}

Entite_Schema::~Entite_Schema()
{

}

void Entite_Schema::creerEntite(std::string lien, Gestionnaire_Images* gi)
{
    std::ifstream fichier(lien.c_str(), std::ios::in);
    std::string valtexte, vide;
    int val = 0;
    if(fichier)
    {
        fichier >> vide >> vide >> valtexte;// Nom
        _nom = valtexte;
        fichier >> vide >> vide >> valtexte;// Description
        _description = valtexte;
        fichier >> vide >> vide >> valtexte;// Image
        _image = gi->get_contenu(valtexte);
        fichier >> vide >> vide >> val;// Vie
        fichier >> vide >> vide >> val;// Moral
        fichier >> vide >> vide >> val;// Force
        fichier >> vide >> vide >> val;// Vitesse
        fichier >> vide >> vide >> val;// Defense
        fichier.close();
    }

}
