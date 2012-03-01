#include "Civilisation.h"

Civilisation::Civilisation(std::string nom, Gestionnaire_Images* gi)
{
    _nom = nom;
    _schemas = new Gestionnaire_Entites(_nom, gi);
    _actives.push_back(new Entite_Active(_schemas->get_contenu("Soldat")));
}

Civilisation::~Civilisation()
{
    for(unsigned int i = 0 ; i < _actives.size() ; i++)
    {
        delete _actives[i];
    }
    delete _schemas;
}

void Civilisation::afficherEntites(sf::RenderWindow* app)
{
    for(unsigned int i = 0 ; i < _actives.size() ; i++)
    {
        app->Draw(*((_actives[i])->get_Sprite()));
    }

}
