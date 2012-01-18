#include "Engine.h"

#include "Engine_Game.h"
#include "Engine_Graphics.h"
#include "Engine_Sound.h"

Engine::Engine(Game* game) : sf::Thread()
{
    _parent = game;
    _encours = false;
}

Engine::~Engine()
{
    _parent = NULL;
}

void Engine::push_event(Engine_Event& e)
{
    std::cout << "Message Envoye" << std::endl;
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

void Engine::lancer()
{
    _encours = true;
}

void Engine::finir()
{
    _encours = false;
}

void Engine::send_message_to_graphics(Engine_Event& e)
{
    _eng_gfx->push_event(e);
}

void Engine::send_message_to_game(Engine_Event& e)
{
    _eng_game->push_event(e);
}

void Engine::send_message_to_sound(Engine_Event& e)
{
    _eng_son->push_event(e);
}

void Engine::attach_engine_game(Engine_Game* eng_game)
{
    _eng_game = eng_game;
}

void Engine::attach_engine_graphics(Engine_Graphics* eng_gfx)
{
    _eng_gfx = eng_gfx;
}

void Engine::attach_engine_sound(Engine_Sound* eng_son)
{
    _eng_son = eng_son;
}
