#include "Scene.h"

Scene::Scene(Gestionnaire_Images* gi)
{
    _gi = gi;
}

Scene::~Scene()
{
    _gi = NULL;
}
