#include "Scene_MenuPrincipal.h"

Scene_MenuPrincipal::Scene_MenuPrincipal(Gestionnaire_Images* gi, sf::RenderWindow* app) : Scene(gi)
{
    int x, y;
    std::string lien = IMG_DOSSIER;
    lien = lien + "buttons.png";
    std::cout<<lien<<std::endl;
    x = (*app).GetWidth();
    y = (*app).GetHeight();
    if (!image.LoadFromFile(lien.c_str()))
    {
        std::cout<<"Erreur durant le chargement de l'image"<<std::endl;
    }
    else
    {
        image.CreateMaskFromColor(sf::Color(181 ,230 ,29 ));
        buttonPlay.SetImage(image);
        buttonQuit.SetImage(image);
    }
    buttonPlay.SetSubRect(sf::IntRect(0,100, 150,160));
    buttonQuit.SetSubRect(sf::IntRect(0,0,150,60));

    buttonPlay.SetPosition(sf::Vector2f(x/2-50, y/2-50));
    buttonQuit.SetPosition(sf::Vector2f(x/2-50,y/2+100));
}

void Scene_MenuPrincipal::run(sf::RenderWindow* app)
{
    (*app).Clear();
    (*app).Draw(buttonPlay);
    (*app).Draw(buttonQuit);
    (*app).Display();
}

void Scene_MenuPrincipal::animation(sf::RenderWindow* app, std::string mess)
{
    if(mess == "MOUSEOVERPLAY")
    {
        buttonPlay.SetSubRect(sf::IntRect(200,100, 350,160));
    }
    if(mess == "MOUSEOVERQUIT")
    {
        buttonQuit.SetSubRect(sf::IntRect(200,0,350,60));
    }
    if(mess == "MOUSEQUITQUIT")
    {
        buttonQuit.SetSubRect(sf::IntRect(0,0,150,60));
    }
    if(mess == "MOUSEQUITPLAY")
    {
        buttonPlay.SetSubRect(sf::IntRect(0,100, 150,160));
    }
    if(mess == "MOUSECLICKPLAY")
    {
    std::cout<<"pddddddddddddddddddddddddddddddddddddd"<<std::endl;;
    }
}
