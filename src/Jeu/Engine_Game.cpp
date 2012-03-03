#include "Engine_Game.h"
#include "../Base/Game.h"

Engine_Game::Engine_Game(Game* game, sf::RenderWindow* app, std::string nom) : Engine(game, app, nom)
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
            * On demande au moteur de s'arréter
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

void Engine_Game::sceneChangee()
{
    if(_parent->get_numeroScene() == CHARGEMENT)
    {
        while(_sceneActive->time() != 1);

        _parent->changerScene(JEU, true);
    }

}
