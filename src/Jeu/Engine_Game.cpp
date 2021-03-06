#include "Engine_Game.h"
#include "../Base/Core.h"

Engine_Game::Engine_Game(Core* game, sf::RenderWindow* app, std::string nom) : Engine(game, app, nom)
{

}

Engine_Game::~Engine_Game()
{

}

void Engine_Game::frame()
{

}

void Engine_Game::Run()
{
    while(!_encours)
    {
        /**
        * Permet de synchroniser le moteur avec les autres moteurs
        */
    }

    while(_encours)
    {

        process_queue();


    }
    std::cout << "Fin GAME" << std::endl;
}

void Engine_Game::event_MenuPrincipal(Engine_Event& e)
{
    switch(e.get_type())
    {
        case MOUSE:

        break;
        case CLICK:
        if(e.get_nom() == "QUIT" && ((e.get_event())->MouseButton.Button) == sf::Mouse::Left)
        {

            _sceneActive = NULL;
            /**
            * On demande au moteur de s'arr�ter
            */
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

void Engine_Game::event_Chargement(Engine_Event& e)
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

void Engine_Game::event_Jeu(Engine_Event& e)
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

void Engine_Game::event_All(Engine_Event& e)
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
        _sceneActive = NULL;
        /**
        * On demande au moteur de s'arr�ter
        */
        _encours = false;
        break;
        default:
        std::cerr << "Impossible de traiter le message : Le Type " << e.get_type() << " est invalide !" << std::endl;
        break;
    }
}

void Engine_Game::sceneChangee()
{
    /*if(_parent->get_numeroScene() == CHARGEMENT)
    {
        while(_sceneActive->time() != 1);

        _parent->changerScene(JEU, true);
    }*/

    _sceneActive->initJeu();
    while(_sceneActive->isInit() == false);
}
