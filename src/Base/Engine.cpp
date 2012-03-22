#include "Engine.h"
#include "Game.h"
#include "../Jeu/Engine_Game.h"
#include "../Gfx/Engine_Graphics.h"
#include "../Son/Engine_Sound.h"

Engine::Engine(Game* game, sf::RenderWindow* app, std::string nom) : sf::Thread()
{
    _parent = game;
    _app = app;
    _nom = nom;
    _sceneActive = NULL;
    _encours = false;
}

Engine::~Engine()
{
    _parent = NULL;
    _app = NULL;
    _sceneActive = NULL;
}

void Engine::push_event(Engine_Event& e)
{
    /**
    * Un message est ajouté au conteneur des messages du moteur visé
    */

    std::cerr << "Message Envoye" << std::endl;
    _events_queue.push(e);
}

void Engine::process_queue()
{
    /**
    * Tant que le conteneur n'est pas vide, on récupère le première message dans une variable, on l'enlève du conteneur et on le traite.
    */
    while (!_events_queue.empty())
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

void Engine::process_event(Engine_Event& e)
{
    std::cerr << _nom << " : " << e.get_nom() << std::endl;

    switch(e.get_scene())
    {
        case MENU_PRINCIPAL:
        event_MenuPrincipal(e);
        break;
        case CHARGEMENT:
        event_Chargement(e);
        break;
        case JEU:
        event_Jeu(e);
        break;
        case ALL:
        event_All(e);
        break;
        default:
        std::cerr << "Impossible de traiter le message : La Scene " << e.get_scene() << " est invalide !" << std::endl;
        break;
    }
}

void Engine::changerSceneActive(Scene* scene)
{
    _sceneActive = scene;
}

bool Engine::sceneFinie()
{
    if(_sceneActive == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

