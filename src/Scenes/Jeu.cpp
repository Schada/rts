#include "Jeu.h"

Jeu::Jeu(sf::RenderWindow* app) : Scene(app)
{
    _humain = NULL;
    _schemas = NULL;
}

Jeu::~Jeu()
{

    delete _humain;
    delete _schemas;
    std::cerr << "FIN SCENE JEU" << std::endl;

}

void Jeu::run()
{
    _app->Clear(sf::Color(200, 0, 0));
    _humain->afficherEntites(_app);
    _app->Draw(Text);
    _app->Display();
}

void Jeu::animation(std::string mess)
{

}

float Jeu::jouerSon(std::string nom)
{
    return 0.f;
}

void Jeu::jouerMusique(std::string nom)
{

}

void Jeu::stopperMusique()
{

}

sf::Sprite* Jeu::get_sprite(std::string nom)
{
    return NULL;
}

void Jeu::initGfx()
{

    _gfxInit = true;
}

void Jeu::initSon()
{
     _sonInit = true;
}

void Jeu::initJeu()
{
    while(_gfxInit == false);

    _schemas = new Gestionnaire_Entites("Schema", _gi);
    _humain = new Civilisation("Humains", _schemas);
    std::cerr << "JEU INIT" << std::endl;
    std::cout << isInit() << std::endl;
    _jeuInit = true;
}
