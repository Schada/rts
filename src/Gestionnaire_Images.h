/**
*   Auteur : Schada
*   Classe : Gestionnaire_Images
*   Role : Gere les images du jeu
*/

#ifndef GESTIONNAIRE_IMAGES_H
#define GESTIONNAIRE_IMAGES_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class Gestionnaire_Images
{
    public:
    Gestionnaire_Images();
    ~Gestionnaire_Images();

    /**
    * Cette methode renvoit le conteneur des images
    */

    std::map < std::string, sf::Image* > getImages();

    /**
    * Methode pour recuperer une image avec son nom
    */

    sf::Image* getImage(std::string nom);

    private:

    std::map < std::string, sf::Image* > _images;
};

#endif // GESTIONNAIRE_IMAGES_H
