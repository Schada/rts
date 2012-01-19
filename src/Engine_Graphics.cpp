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
}

void Engine_Graphics::Run()
{
    while(!_encours)
    {
    }
    Engine_Event e1("Graphics to Game 1/2");
    Engine_Event e2("Graphics to Game 2/2");
    Engine_Event e3("Graphics to Sound 1/1");
    send_message_to_game(e1);
    send_message_to_game(e2);
    send_message_to_sound(e3);
    std::cout << "Graphics Go !" << std::endl;
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
