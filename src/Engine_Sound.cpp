#include "Engine_Sound.h"

Engine_Sound::Engine_Sound(Game* game, sf::RenderWindow* app, std::string nom) : Engine(game, app, nom)
{
    _sound = new sf::Sound();
    _buffer = NULL;
    _music = NULL;
    _gs = new Gestionnaire_Sons();
    _gm = new Gestionnaire_Musiques();
}

Engine_Sound::~Engine_Sound()
{
    delete _sound;
    _buffer = NULL;
    _music = NULL;
    delete _gs;
    delete _gm;

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
    _music = _gm->get_contenu("test");
    _music->Play();
    while(_encours)
    {

        process_queue();
    }
    _music->Stop();
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
        if(e.get_parametre() =="LEFT" && (e.get_nom()== "QUIT" || e.get_nom()== "PLAY"))
        {
            std::cout << "Sound en cours" << std::endl;
            _buffer = (_gs->get_contenu("t"));
            std::cout << "Buffer recupérer" << std::endl;
            _sound->SetBuffer(*_buffer);
            std::cout << "Buffer assimiler" << std::endl;
            _sound->Play();
            std::cout << "Sons play" << std::endl;
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
