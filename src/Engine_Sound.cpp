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
    if(e.get_nb() == "QUIT")
    {
        _encours = false;

    }
}

void Engine_Sound::Run()
{
    while(!_encours)
    {
    }

    while(_encours)
    {

        process_queue();
    }
}
