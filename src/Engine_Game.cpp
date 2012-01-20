#include "Engine_Game.h"


Engine_Game::Engine_Game(Game* game, sf::RenderWindow* app) : Engine(game, app)
{

}

Engine_Game::~Engine_Game()
{

}

void Engine_Game::frame()
{

}

void Engine_Game::process_event(Engine_Event& e)
{
    std::cout << "Game : " << e.get_nom() << std::endl;
    switch(e.get_scene())
    {
        case MENU_PRINCIPAL:
        switch(e.get_type())
        {
            case MOUSE:

            break;
            case CLICK:
            if(e.get_parametre() == "LEFT" && e.get_nom() == "QUIT" )
            {
                _encours = false;
            }
            break;
            case KEY:

            break;
            case LOAD:

            break;
            default:
            std::cerr << "Impossible de traiter le message" << std::endl;
            break;
        }
        break;
        case CHARGEMENT:

        break;
        case JEU:

        break;
        default:
        std::cerr << "Impossible de traiter le message" << std::endl;
        break;
    }
}

void Engine_Game::Run()
{
    while(!_encours)
    {
    }

    while(_encours)
    {

        process_queue();

    }
}
