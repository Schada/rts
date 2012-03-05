#include "Gestionnaire.h"

Gestionnaire::Gestionnaire()
{
    _nom = "";
    _lienFichier = "";
    _lienDossier = "";
}

Gestionnaire::~Gestionnaire()
{
    std::map< std::string, void* >::iterator it;

    for (it = _conteneur.begin(); it != _conteneur.end(); it++)
    {
        if(it->second)
        {
            delete it->second;
            it->second = NULL;
        }
    }

    _conteneur.clear();
}

std::map < std::string, void* > Gestionnaire::get_conteneur()
{
    return _conteneur;
}

void Gestionnaire::creerGestionnaire(std::string balise)
{
    std::ifstream fichier(_lienFichier.c_str(), std::ios::in);
    if(fichier)
    {
        std::string ligne;

        // Parcourt le fichier jusqu'� trouver la balise ou la fin du fichier
        do
        {
        }while((getline(fichier, ligne)) && (ligne != balise));
        if(ligne == balise) // Si la balise a �t� trouver
        {
            std::string nom, lien;

            //On parcourt les lignes de la balise jusqu'� la balise [Fin]

            do
            {
                fichier >> nom;
                if(nom != "[Fin]")
                {
                    if(!existe(nom))
                    {
                        inserer(nom);
                    }

                }

            }while((!fichier.eof()) && (nom != "[Fin]"));

            if(nom != "[Fin]") // Si la balise [Fin] n'a pas �t� trouver
            {
                std::cout << "Balise [Fin] de " + balise + " introuvable" << std::endl;
            }

        }
        else // Si la balise consern�e n'a pas �t� trouver
        {
            std::cout << "Balise " + balise + " introuvable" << std::endl;
        }
        fichier.close();
    }
    else
    {
        std::cout << "Le fichier " << _lienFichier << " est introuvable." << std::endl;
    }
}

 bool Gestionnaire::existe(std::string nom)
 {
    std::map< std::string, void* >::iterator it;

    for (it = _conteneur.begin(); it != _conteneur.end(); it++)
    {
        if(it->first == nom)
        {
            return true;
        }
    }
    return false;
 }
