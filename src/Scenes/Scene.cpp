#include "Scene.h"


Scene::Scene(sf::RenderWindow* app)
{
    _app = app;
    _gi = NULL;
    _gm = NULL;
    _gs = NULL;
    _gfxInit = false;
    _sonInit = false;
}

Scene::~Scene()
{
    _app = NULL;
    _gi = NULL;
    _gm = NULL;
    _gs = NULL;
}

void Scene::set_gi(Gestionnaire_Images* gi)
{
    _gi = gi;
}

void Scene::set_gm(Gestionnaire_Musiques* gm)
{
    _gm = gm;
}

void Scene::set_gs(Gestionnaire_Sons* gs)
{
    _gs = gs;
}

bool Scene::isInit()
{
    return(_gfxInit && _sonInit);
}

float Scene::time()
{
    return floor(_clock.GetElapsedTime());
}
