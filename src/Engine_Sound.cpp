#include "Engine_Sound.h"

Engine_Sound::Engine_Sound(Game* game, sf::RenderWindow* app) : Engine(game, app)
{

}

Engine_Sound::~Engine_Sound()
{

}

void Engine_Sound::frame()
{

}

void Engine_Sound::process_event(Engine_Event& e)
{
    std::cout << "Sound : " << e.get_nb() << std::endl;
}

void Engine_Sound::Run()
{
    while(!_encours)
    {
    }
    Engine_Event e1("Sound to Game 1/1");
    Engine_Event e2("Sound to Graphics 1/1");
    send_message_to_game(e1);
    send_message_to_graphics(e2);
    std::cout << "Sound Go !" << std::endl;
    while(_encours)
    {

        process_queue();
    }
}
