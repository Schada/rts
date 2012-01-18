#include "Engine.h"

Engine::Engine(Game* game) : sf::Thread()
{
    _parent = game;
}

Engine::~Engine()
{
    _parent = NULL;
}

void Engine::push_event(Engine_Event& e)
{
    std::cout << "Message Envoyé" << std::endl;
    _events_queue.push(e);
}

void Engine::process_queue()
{
    while (! _events_queue.empty())
    {
			Engine_Event e = _events_queue.front();
			_events_queue.pop();

			process_event(e);
    }
}

void Engine::Run()
{
    encours = true;
    std::cout << "Run !!!" << std::endl;
    while(encours)
    {


        process_queue();
    }
}

void Engine::process_event(Engine_Event& e)
{
    switch(e.get_nb())
    {
        case 0 :
            std::cout << "Son OK" << std::endl;
        break;
        case 1 :
            std::cout << "Graphique OK" << std::endl;
        break;
        default :
            std::cout << "Erreur" << std::endl;
        break;
    }
}

void Engine::finir()
{
    encours = false;
}
