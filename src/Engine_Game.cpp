#include "Engine_Game.h"


Engine_Game::Engine_Game(Game* game) : Engine(game)
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
}

void Engine_Game::Run()
{
    while(!_encours)
    {
    }
    Engine_Event e1("Game to Graphics 1/2");
    Engine_Event e2("Game to Graphics 2/2");
    Engine_Event e3("Game to Sound 1/1");
    send_message_to_graphics(e1);
    send_message_to_sound(e3);
    send_message_to_graphics(e2);
    std::cout << "Game Go !" << std::endl;
    while(_encours)
    {

        process_queue();
    }
}
