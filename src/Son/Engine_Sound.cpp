#include "Engine_Sound.h"
#include "../Base/Game.h"

Engine_Sound::Engine_Sound(Game* game, sf::RenderWindow* app, std::string nom) : Engine(game, app, nom)
{
	_gm = new Gestionnaire_Musiques();
	_gs = new Gestionnaire_Sons();
}

Engine_Sound::~Engine_Sound()
{
    delete _gm;
    delete _gs;
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
    //_sceneActive->stopperMusique();
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
            _sceneActive = NULL;
            /**
            * On demande au moteur de s'arréter
            */
            _encours = false;
        }
        if(e.get_parametre() =="LEFT" && e.get_nom()== "PLAY")
        {
            _sceneActive->stopperMusique();

            sf::Sleep(_sceneActive->jouerSon("t"));

            _parent->changerScene(CHARGEMENT, true);

        }
        break;
        case KEY:

        break;
        case LOAD:
        if(e.get_nom() == "MUSIQUE")
        {
            _sceneActive->jouerMusique(e.get_parametre());
        }
        break;
        case CHANGE:

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
        case CHANGE:

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
        case CHANGE:

        break;
        default:
        std::cerr << "Impossible de traiter le message : Le Type " << e.get_type() << " est invalide !" << std::endl;
        break;
    }
}

void Engine_Sound::sceneChangee()
{
    _sceneActive->set_gm(_gm);
    _sceneActive->set_gs(_gs);
    _sceneActive->initSon();
}
