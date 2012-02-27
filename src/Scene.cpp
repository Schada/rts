#include "Scene.h"


Scene::Scene(sf::RenderWindow* app, Gestionnaire_Images* gi, Gestionnaire_Musiques* gm, Gestionnaire_Sons* gs)
{
    _app = app;
    _gi = gi;
    _gm = gm;
    _gs = gs;
}

Scene::~Scene()
{
    _app = NULL;
    _gi = NULL;
    _gm = NULL;
    _gs = NULL;
}
