#include "Scene_Jeu.h"

Scene_Jeu::Scene_Jeu(sf::RenderWindow* app) : Scene(app)
{
    _humain = NULL;
}

Scene_Jeu::~Scene_Jeu()
{
    delete _humain;
}

void Scene_Jeu::run()
{
    _app->Clear(sf::Color(200, 0, 0));
    _humain->afficherEntites(_app);
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
    _humain = new Civilisation("Humains", _gi);

    _gfxInit = true;
}

void Scene_Jeu::initSon()
{
     _sonInit = true;
}
