#include "Civilisation.h"

Civilisation::Civilisation(std::string nom, Gestionnaire_Images* gi)
{
    _nom = nom;
    _schemas = new Gestionnaire_Entites(_nom, gi);
}

Civilisation::~Civilisation()
{
    for(unsigned int i = 0 ; i < _actives.size() ; i++)
    {
        delete _actives[i];
    }
    delete _schemas;
}
