#include "Scene_Globale.h"

Scene_Globale::Scene_Globale(sf::RenderWindow* app, Scene_Locale* console, std::string nom, std::string fond) : Scene(app, nom, fond)
{
    _console = console;
}

Scene_Globale::~Scene_Globale()
{
    _console = NULL;

}

void Scene_Globale::afficher()
{
    // Efface l'�cran (remplissage avec du noir)
    _app->Clear();

    Scene::afficher();



    // Affichage du contenu de la fen�tre � l'�cran
    _app->Display();

}
