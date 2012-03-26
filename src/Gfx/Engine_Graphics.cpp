#include "Engine_Graphics.h"
#include "../Base/Core.h"

Engine_Graphics::Engine_Graphics(Core* game, sf::RenderWindow* app, std::string nom) : Engine(game, app, nom)
{
    _gi = new Gestionnaire_Images();
}

Engine_Graphics::~Engine_Graphics()
{
    delete _gi;
}

void Engine_Graphics::frame()
{

}

void Engine_Graphics::Run()
{
    while(!_encours)
    {
        /**
        * Permet de synchroniser le moteur avec les autres moteurs
        */
    }

    /**
    * On autorise le moteur graphics à modifier la fenetre de rendu
    */
    _app->SetActive();


    while(_encours)
    {

        if(_sceneActive != NULL)
        {
            /**
            *Si une scene est active alors on exécute son methode run
            */

            Core::win_mu->Lock();
            _sceneActive->afficher();
            Core::win_mu->Unlock();

        }
        process_queue();
    }
    std::cout << "Fin GFX" << std::endl;
}

void Engine_Graphics::event_MenuPrincipal(Engine_Event& e)
{
    switch(e.get_type())
    {
        case MOUSE:
        {
        /** <---------------------------------------- Déclaration variables début ------------------------------------------->*/

            sf::Vector2f PlaySize = (_sceneActive->get_sprite("Play"))->GetSize();
            sf::Vector2f PlayPos = (_sceneActive->get_sprite("Play"))->GetPosition();
            sf::Vector2f QuitPos = (_sceneActive->get_sprite("Quit"))->GetPosition();

            int MouseX = e.get_event()->MouseButton.X;
            int MouseY = e.get_event()->MouseButton.Y;
        /** <---------------------------------------- Déclaration variables fin ------------------------------------------->*/
            if( MouseX > PlayPos.x && MouseX < PlayPos.x + PlaySize.x && MouseY > PlayPos.y && MouseY < PlayPos.y + PlaySize.y )
            {
                _sceneActive->animation("MOUSEOVERPLAY");
            }else
                {
                _sceneActive->animation("MOUSEQUITPLAY");
                }
            if(MouseX > QuitPos.x && MouseX < (QuitPos.x + 150) && MouseY > QuitPos.y && MouseY < (QuitPos.y+ 60) )
            {
                _sceneActive->animation("MOUSEOVERQUIT");
            }else
            {
                _sceneActive->animation("MOUSEQUITQUIT");
            }
        }
        break;
        case CLICK:
            if(e.get_nom() == "QUIT" && ((e.get_event()))->MouseButton.Button == sf::Mouse::Left)
            {
                /**
                * On supprime la scene active, on ferme la fenetre de rendu et on demande au moteur de s'arréter
                */
                _app->Close();
                _sceneActive = NULL;
                _encours = false;

            }
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

void Engine_Graphics::event_Chargement(Engine_Event& e)
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

void Engine_Graphics::event_Jeu(Engine_Event& e)
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

void Engine_Graphics::event_All(Engine_Event& e)
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
        if(e.get_nom() == "NULL")
        {
            _sceneActive = NULL;
        }
        else
        {
            _sceneActive = _parent->get_Scene();
            sceneChangee();
        }

        break;
        case QUIT:
        _app->Close();
        _sceneActive = NULL;
        /**
        * On demande au moteur de s'arréter
        */
        _encours = false;
        break;
        default:
        std::cerr << "Impossible de traiter le message : Le Type " << e.get_type() << " est invalide !" << std::endl;
        break;
    }
}

void Engine_Graphics::sceneChangee()
{
    _sceneActive->set_gi(_gi);
    Core::win_mu->Lock();
    _sceneActive->initGfx();
    Core::win_mu->Unlock();
    while(_sceneActive->isInit() == false);
    std::cout << "Scene INIT : " << std::endl << std::endl;
}
