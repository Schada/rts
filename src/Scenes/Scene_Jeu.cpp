#include "Scene_Jeu.h"

Scene_Jeu::Scene_Jeu(sf::RenderWindow* app) : Scene(app)
{
    _humain = NULL;
    _schemas = NULL;
}

Scene_Jeu::~Scene_Jeu()
{

    delete _humain;
    delete _schemas;
    std::cerr << "FIN" << std::endl;

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

    _gfxInit = true;
}

void Scene_Jeu::initSon()
{
     _sonInit = true;
}

void Scene_Jeu::initJeu()
{
    while(_gfxInit == false);

    _schemas = new Gestionnaire_Entites("Schema", _gi);
    _humain = new Civilisation("Humains", _schemas);
    std::cerr << "JEU INIT" << std::endl;
    std::cout << isInit() << std::endl;
    _jeuInit = true;
}
