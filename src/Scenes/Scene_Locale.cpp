#include "Scene_Locale.h"

Scene_Locale::Scene_Locale(sf::RenderWindow* app, std::string nom, std::string fond, bool deplacer, bool tete) : Scene(app, nom, fond)
{
    _deplacer = deplacer;
    _tete = tete;
}

Scene_Locale::~Scene_Locale()
{

}

void Scene_Locale::afficher()
{

}
