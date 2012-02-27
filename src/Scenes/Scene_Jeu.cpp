#include "Scene_Jeu.h"

Scene_Jeu::Scene_Jeu(sf::RenderWindow* app) : Scene(app)
{

}

Scene_Jeu::~Scene_Jeu()
{

}

void Scene_Jeu::run()
{
    _app->Clear();
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
    _gfxInit = true;
}

void Scene_Jeu::initSon()
{
     _sonInit = true;
}
