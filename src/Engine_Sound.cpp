#include "Engine_Sound.h"

Engine_Sound::Engine_Sound(Game* game, sf::RenderWindow* app, std::string nom) : Engine(game, app, nom)
{

}

Engine_Sound::~Engine_Sound()
{

}

void Engine_Sound::frame()
{

}

void Engine_Sound::Run()
{
    while(!_encours)
    {
        /**
        * Permet de synchroniser le moteur avec les autres moteurs
        */
    }

    while(_encours)
    {

        process_queue();
    }
}

void Engine_Sound::event_MenuPrincipal(Engine_Event& e)
{
    switch(e.get_type())
    {
        case MOUSE:

        break;
        case CLICK:
        if(e.get_parametre() == "LEFT" && e.get_nom() == "QUIT" )
        {
            /**
            * On demande au moteur de s'arréter
            */
            _encours = false;
        }
        if(e.get_parametre() =="LEFT" && e.get_nom()== "QUIT" && e.get_nom()== "PLAY")
        {
            sf::Sound sound;
            sf::SoundBuffer buffer = *(_gs->get_contenu("Click"));
            sound.SetBuffer(buffer);
            sound.Play();
        }
        break;
        case KEY:

        break;
        case LOAD:

        break;
        default:
        std::cerr << "Impossible de traiter le message : Le Type " << e.get_type() << " est invalide !" << std::endl;
        break;
    }
}

void Engine_Sound::event_Chargement(Engine_Event& e)
{
    switch(e.get_type())
    {
        case MOUSE:

        break;
        case CLICK:

        break;
        case KEY:

        break;
        case LOAD:

        break;
        default:
        std::cerr << "Impossible de traiter le message : Le Type " << e.get_type() << " est invalide !" << std::endl;
        break;
    }
}

void Engine_Sound::event_Jeu(Engine_Event& e)
{
    switch(e.get_type())
    {
        case MOUSE:

        break;
        case CLICK:

        break;
        case KEY:

        break;
        case LOAD:

        break;
        default:
        std::cerr << "Impossible de traiter le message : Le Type " << e.get_type() << " est invalide !" << std::endl;
        break;
    }
}
