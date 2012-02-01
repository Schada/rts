#include "Scene_MenuPrincipal.h"

Scene_MenuPrincipal::Scene_MenuPrincipal(Gestionnaire_Images* gi, Gestionnaire_Sons* gs, sf::RenderWindow* app) : Scene(gi)
{
    int x, y;

    x = (*app).GetWidth();
    y = (*app).GetHeight();

    image = *(_gi->get_contenu("Buttons"));
    imageFond = *(_gi ->get_contenu("Fond"));

    fondEcran.SetImage(imageFond);
    buttonPlay.SetImage(image);
    buttonQuit.SetImage(image);

    sf::Color pixel = buttonPlay.GetPixel(0, 0);
    image.CreateMaskFromColor(pixel);

    buttonPlay.SetSubRect(sf::IntRect(0*image.GetWidth()/2,2*image.GetHeight()/3, 1*image.GetWidth()/2,3*image.GetHeight()/3));
    buttonQuit.SetSubRect(sf::IntRect(0*image.GetWidth()/2,1*image.GetHeight()/3, 1*image.GetWidth()/2,2*image.GetHeight()/3));

    fondEcran.SetPosition(0,0);
    fondEcran.Resize(800,600); /// Pour l'instant jeune pd
    buttonPlay.SetPosition(sf::Vector2f(x/2-50, y/2-50));
    buttonQuit.SetPosition(sf::Vector2f(x/2-50,y/2+100));

}

void Scene_MenuPrincipal::run(sf::RenderWindow* app)
{
    (*app).Clear();
    (*app).Draw(fondEcran);
    (*app).Draw(buttonPlay);
    (*app).Draw(buttonQuit);
    (*app).Display();
}

void Scene_MenuPrincipal::animation(sf::RenderWindow* app, std::string mess)
{
    if(mess == "MOUSEOVERPLAY")
    {
        buttonPlay.SetSubRect(sf::IntRect(1*image.GetWidth()/2,2*image.GetHeight()/3, 2*image.GetWidth()/2,3*image.GetHeight()/3));

    }
    if(mess == "MOUSEOVERQUIT")
    {
        buttonQuit.SetSubRect(sf::IntRect(1*image.GetWidth()/2,1*image.GetHeight()/3, 2*image.GetWidth()/2,2*image.GetHeight()/3));
    }
    if(mess == "MOUSEQUITQUIT")
    {
        buttonQuit.SetSubRect(sf::IntRect(56,191,230,240));
    }
    if(mess == "MOUSEQUITPLAY")
    {
        buttonPlay.SetSubRect(sf::IntRect(73,350, 193,398));
    }
    if(mess == "MOUSECLICKPLAY")
    {

    }
}
