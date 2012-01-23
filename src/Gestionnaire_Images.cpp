#include "Gestionnaire_Images.h"

Gestionnaire_Images::Gestionnaire_Images()
{

}

Gestionnaire_Images::~Gestionnaire_Images()
{
    std::map< std::string, sf::Image* >::iterator it;

    for (it = _images.begin(); it != _images.end(); it++)
    {
        if(it->second)
        {
            delete it->second;
            it->second = NULL;
        }
    }

    _images.clear();
}

/*
Cette methode renvoit le conteneur des images
*/

std::map < std::string, sf::Image* > Gestionnaire_Images::getImages()
{
    return _images;
}

/*
Methode pour recuperer une image avec son nom
*/

sf::Image* Gestionnaire_Images::getImage(std::string nom)
{
    std::map< std::string, sf::Image* >::iterator it = _images.find(nom);
    if(it != _images.end())
    {
        return it->second;
    }
    else
    {
        return NULL;
    }
}
