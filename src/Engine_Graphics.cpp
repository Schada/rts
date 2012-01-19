#include "Engine_Graphics.h"


Engine_Graphics::Engine_Graphics(Game* game, sf::RenderWindow* app) : Engine(game, app)
{
    _sceneActive = NULL;
}

Engine_Graphics::~Engine_Graphics()
{
    if(_sceneActive)
        delete _sceneActive;
}

void Engine_Graphics::frame()
{

}

void Engine_Graphics::process_event(Engine_Event& e)
{
    std::cout << "Graphics : " << e.get_nb() << std::endl;
    if(e.get_nb() == "QUIT")
    {
        delete _sceneActive;
        _sceneActive = NULL;
        _app->Close();
        _encours = false;

    }
    if(e.get_nb() == "MOUSEOVERQUIT")
    {
        _sceneActive->animation(_app, "MOUSEOVERQUIT");
    }
    if(e.get_nb() == "MOUSEOVERPLAY")
    {
        _sceneActive->animation(_app, "MOUSEOVERPLAY");
    }
}

void Engine_Graphics::Run()
{
    while(!_encours)
    {
    }
    _app->SetActive(true);
    Gestionnaire_Images gi;
    Scene_MenuPrincipal* scene = new Scene_MenuPrincipal(&gi, _app);
    _sceneActive = scene;
    while(_encours)
    {
        process_queue();
        if(_sceneActive)
        {
            _sceneActive->run(_app);
        }

    }
}
