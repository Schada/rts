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
    std::cout << "Game : " << e.get_nb() << std::endl;
    if(e.get_nb() == "QUIT")
    {
        _encours = false;

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
