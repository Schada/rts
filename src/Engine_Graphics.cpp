#include "Engine_Graphics.h"


Engine_Graphics::Engine_Graphics(Game* game, sf::RenderWindow* app) : Engine(game, app)
{
    _sceneActive = NULL;
}

Engine_Graphics::~Engine_Graphics()
{
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
        _app->Close();
    }
}

void Engine_Graphics::Run()
{
    while(!_encours)
    {
    }
    _app->SetActive(true);
    Gestionnaire_Images gi;
    Scene_MenuPrincipal* scene = new Scene_MenuPrincipal(&gi);
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
