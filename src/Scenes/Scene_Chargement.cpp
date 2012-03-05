#include "Scene_Chargement.h"

Scene_Chargement::Scene_Chargement(sf::RenderWindow* app) : Scene(app)
{

}

Scene_Chargement::~Scene_Chargement()
{

}

void Scene_Chargement::run()
{
    if(floor(_clock.GetElapsedTime()) == 5)
    {
        Text.SetText(L"Ce temps de chargement durent 1000 secondes !");
    }
    else if(floor(_clock.GetElapsedTime()) == 10)
    {
        Text.SetText(L"Non je plaisante seulement 100 :p");
    }
    else if(floor(_clock.GetElapsedTime()) == 15)
    {
        Text.SetText(L"C'est le dernier texte, Content ??? ");
    }
    _app->Clear();
    _app->Draw(Text);
    _app->Display();
}

void Scene_Chargement::animation(std::string mess)
{

}

float Scene_Chargement::jouerSon(std::string nom)
{
    return 0.f;
}

void Scene_Chargement::jouerMusique(std::string nom)
{

}

void Scene_Chargement::stopperMusique()
{

}

sf::Sprite* Scene_Chargement::get_sprite(std::string nom)
{
    return NULL;
}

void Scene_Chargement::initGfx()
{
    _clock.Reset();
    // Chargement de la police à partir d'un fichier

    if (!MyFont.LoadFromFile("arial.ttf", 50))
    {
        // Erreurr...
    }

    Text.SetText(L"Le Krakoukass est un oiseau imaginaire issu des schtroumpfs.");
    Text.SetFont(MyFont);
    Text.SetSize(20);

    _gfxInit = true;
}

void Scene_Chargement::initSon()
{
     _sonInit = true;
}

void Scene_Chargement::initJeu()
{
    _jeuInit = true;
}
