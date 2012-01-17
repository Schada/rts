#include "Engine.h"

Engine::Engine(Game* game)
{

}

Engine::~Engine()
{

}

void Engine::push_event(Engine_Event& e)
{
    _events_queue.push(e);
}

void Engine::process_queue()
{
    while (! _events_queue.empty())
    {
			Engine_Event e = _events_queue.front();
			_events_queue.pop();

			_process_event(e);
    }
}
