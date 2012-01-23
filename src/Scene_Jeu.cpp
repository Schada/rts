#include "Scene_Jeu.h"

Scene_Jeu::Scene_Jeu(Gestionnaire_Images* gi) : Scene(gi)
{

}

Scene_Jeu::~Scene_Jeu()
{

}

void Scene_Jeu::run(sf::RenderWindow* app)
{
    (*app).Clear();
    (*app).Display();
}

void Scene_Jeu::animation(sf::RenderWindow* app, std::string mess)
{

}
