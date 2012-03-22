#include "Engine_Graphics.h"
#include "../Base/Game.h"

Engine_Graphics::Engine_Graphics(Game* game, sf::RenderWindow* app, std::string nom) : Engine(game, app, nom)
{
    _gi = new Gestionnaire_Images();
}

Engine_Graphics::~Engine_Graphics()
{
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
    _app->SetActive();


    while(_encours)
    {

        if(_sceneActive != NULL)
        {
            /**
            *Si une scene est active alors on exécute son methode run
            */

            Game::win_mu->Lock();
            _sceneActive->run();
            Game::win_mu->Unlock();

        }
        process_queue();
    }
    std::cout << "Fin GFX" << std::endl;
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
        if(e.get_nom() == "QUIT" && ((e.get_event()))->MouseButton.Button == sf::Mouse::Left)
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

void Engine_Graphics::event_All(Engine_Event& e)
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
        if(e.get_nom() == "NULL")
        {
            _sceneActive = NULL;
        }
        else
        {
            _sceneActive = _parent->get_Scene();
            sceneChangee();
        }

        break;
        case QUIT:
        _app->Close();
        _sceneActive = NULL;
        /**
        * On demande au moteur de s'arréter
        */
        _encours = false;
        break;
        default:
        std::cerr << "Impossible de traiter le message : Le Type " << e.get_type() << " est invalide !" << std::endl;
        break;
    }
}

void Engine_Graphics::sceneChangee()
{
    _sceneActive->set_gi(_gi);
    Game::win_mu->Lock();
    _sceneActive->initGfx();
    Game::win_mu->Unlock();
    while(_sceneActive->isInit() == false);
    std::cout << "Scene INIT : " << std::endl << std::endl;
}
