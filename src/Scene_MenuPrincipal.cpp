#include "Scene_MenuPrincipal.h"

Scene_MenuPrincipal::Scene_MenuPrincipal(Gestionnaire_Images* gi) : Scene(gi)
{

}

void Scene_MenuPrincipal::run(sf::RenderWindow* app)
{

    app->Clear();
    app->Display();
}
