#include "Scene_Jeu.h"

Scene_Jeu::Scene_Jeu(sf::RenderWindow* app) : Scene(app)
{

}

Scene_Jeu::~Scene_Jeu()
{

}

void Scene_Jeu::run()
{
    _app->Clear(sf::Color(200, 0, 0));
    _app->Draw(Text);
    _app->Display();
}

void Scene_Jeu::animation(std::string mess)
{

}

float Scene_Jeu::jouerSon(std::string nom)
{
    return 0.f;
}

void Scene_Jeu::jouerMusique(std::string nom)
{

}

void Scene_Jeu::stopperMusique()
{

}

sf::Sprite* Scene_Jeu::get_sprite(std::string nom)
{
    return NULL;
}

void Scene_Jeu::initGfx()
{
    if (!MyFont.LoadFromFile("arial.ttf", 50))
    {
        // Erreurr...
    }

    Text.SetText(L"Scene Jeu");
    Text.SetFont(MyFont);
    Text.SetSize(20);

    _gfxInit = true;
}

void Scene_Jeu::initSon()
{
     _sonInit = true;
}
