#include "Scene_MenuPrincipal.h"

Scene_MenuPrincipal::Scene_MenuPrincipal(Gestionnaire_Images* gi) : Scene(gi)
{
    std::string lien = IMG_DOSSIER;
    lien = lien + "buttons.png";
    std::cout<<lien<<std::endl;

    if (!image.LoadFromFile(lien.c_str()))
    {
        std::cout<<"Erreur durant le chargement de l'image"<<std::endl;
    }
    else
    {
        buttonPlay.SetImage(image);
        buttonQuit.SetImage(image);
    }
    buttonPlay.SetSubRect(sf::IntRect(0,0,150,80));
    buttonQuit.SetSubRect(sf::IntRect(40,0,150,65));

    buttonPlay.SetPosition(sf::Vector2f(0 ,0));
    buttonQuit.SetPosition(sf::Vector2f(120 ,120));
}

void Scene_MenuPrincipal::run(sf::RenderWindow* app)
{
    (*app).Draw(buttonPlay);
    (*app).Draw(buttonQuit);
    (*app).Clear();
    (*app).Display();
}
