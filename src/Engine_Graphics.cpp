#include "Engine_Graphics.h"
#include "Game.h"

Engine_Graphics::Engine_Graphics(Game* game, sf::RenderWindow* app, std::string nom) : Engine(game, app, nom)
{

}

Engine_Graphics::~Engine_Graphics()
{

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


    while(_encours)
    {

        if(_sceneActive != NULL)
        {
            /**
            *Si une scene est active alors on exécute son methode run
            */
            _sceneActive->run();
        }
        process_queue();
    }
}

void Engine_Graphics::event_MenuPrincipal(Engine_Event& e)
{
    switch(e.get_type())
    {
        case MOUSE:
        /*if(e.get_nom() == "QUIT" && e.get_parametre() == "IN")
        {
            _sceneActive->animation("MOUSEOVERQUIT");
        }
        if(e.get_nom() == "QUIT" && e.get_parametre() == "OUT")
        {
            _sceneActive->animation("MOUSEQUITQUIT");
        }
        if(e.get_nom() == "PLAY" && e.get_parametre() == "IN")
        {
            _sceneActive->animation("MOUSEOVERPLAY");
        }
        if(e.get_nom() == "PLAY" && e.get_parametre() == "OUT")
        {
            _sceneActive->animation("MOUSEQUITPLAY");
        }*/
        break;
        case CLICK:
        if(e.get_nom() == "QUIT" && e.get_parametre() == "LEFT")
        {
            /**
            * On supprime la scene active, on ferme la fenetre de rendu et on demande au moteur de s'arréter
            */
            _app->Close();
            _sceneActive = NULL;
            _encours = false;
        }
        break;
        case KEY:

        break;
        case LOAD:

        break;
        case CHANGE:

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
        case CHANGE:

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
        case CHANGE:

        break;
        default:
        std::cerr << "Impossible de traiter le message : Le Type " << e.get_type() << " est invalide !" << std::endl;
        break;
    }
}
