#include "Engine_Graphics.h"


Engine_Graphics::Engine_Graphics(Game* game, sf::RenderWindow* app, std::string nom) : Engine(game, app, nom)
{
    _sceneActive = NULL;
     _gi = new Gestionnaire_Images();
}

Engine_Graphics::~Engine_Graphics()
{
    if(_sceneActive)
        delete _sceneActive;
   if(_gi)
        delete _gi;
}

void Engine_Graphics::frame()
{

}

void Engine_Graphics::Run()
{
    while(!_encours)
    {
        /**
        * Permet de synchroniser le moteur avec les autres moteurs
        */
    }
    /**
    * On autorise le moteur graphics à modifier la fenetre de rendu
    */
    _app->SetActive(true);
    /**
    * On créé et active la première scene du jeu , le Menu Principal
    */
    Scene_MenuPrincipal* scene = new Scene_MenuPrincipal(_gi, _app);
    _sceneActive = scene;

    while(_encours)
    {
        process_queue();
        if(_sceneActive)
        {
            /**
            *Si une scene est active alors on exécute son methode run
            */
            _sceneActive->run(_app);
        }

    }
}

void Engine_Graphics::event_MenuPrincipal(Engine_Event& e)
{
    switch(e.get_type())
    {
        case MOUSE:
        if(e.get_nom() == "QUIT" && e.get_parametre() == "IN")
        {
            _sceneActive->animation(_app, "MOUSEOVERQUIT");
        }
        if(e.get_nom() == "QUIT" && e.get_parametre() == "OUT")
        {
            _sceneActive->animation(_app, "MOUSEQUITQUIT");
        }
        if(e.get_nom() == "PLAY" && e.get_parametre() == "IN")
        {
            _sceneActive->animation(_app, "MOUSEOVERPLAY");
        }
        if(e.get_nom() == "PLAY" && e.get_parametre() == "OUT")
        {
            _sceneActive->animation(_app, "MOUSEQUITPLAY");
        }
        break;
        case CLICK:
        if(e.get_nom() == "QUIT" && e.get_parametre() == "LEFT")
        {
            /**
            * On supprime la scene active, on ferme la fenetre de rendu et on demande au moteur de s'arréter
            */
            delete _sceneActive;
            _sceneActive = NULL;
            _app->Close();
            _encours = false;
        }
        if(e.get_nom()== "PLAY" && e.get_parametre() == "LEFT")
        {
            delete _sceneActive;
            _sceneActive = new Scene_Jeu(_gi);
        }
        break;
        case KEY:

        break;
        case LOAD:

        break;
        default:
        std::cerr << "Impossible de traiter le message : Le Type " << e.get_type() << " est invalide !" << std::endl;
        break;
    }
}

void Engine_Graphics::event_Chargement(Engine_Event& e)
{
    switch(e.get_type())
    {
        case MOUSE:

        break;
        case CLICK:

        break;
        case KEY:

        break;
        case LOAD:

        break;
        default:
        std::cerr << "Impossible de traiter le message : Le Type " << e.get_type() << " est invalide !" << std::endl;
        break;
    }
}

void Engine_Graphics::event_Jeu(Engine_Event& e)
{
    switch(e.get_type())
    {
        case MOUSE:

        break;
        case CLICK:

        break;
        case KEY:

        break;
        case LOAD:

        break;
        default:
        std::cerr << "Impossible de traiter le message : Le Type " << e.get_type() << " est invalide !" << std::endl;
        break;
    }
}
