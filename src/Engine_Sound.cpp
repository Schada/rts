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
    std::cout << "Sound : " << e.get_nom() << std::endl;
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
