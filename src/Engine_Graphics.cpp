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
    std::cout << "Graphics : " << e.get_nom() << std::endl;

    switch(e.get_scene())
    {
        case MENU_PRINCIPAL:
        switch(e.get_type())
        {
            case MOUSE:
            if(e.get_nom() == "QUIT" && e.get_parametre() == "IN")
            {
                _sceneActive->animation(_app, "MOUSEOVERQUIT");
            }
            if(e.get_nom() == "QUIT" && e.get_parametre() == "OUT")
            {
                _sceneActive->animation(_app, "MOUSEQUITQUIT");
            }
            if(e.get_nom() == "PLAY" && e.get_parametre() == "IN")
            {
                _sceneActive->animation(_app, "MOUSEOVERPLAY");
            }
            if(e.get_nom() == "PLAY" && e.get_parametre() == "OUT")
            {
                _sceneActive->animation(_app, "MOUSEQUITPLAY");
            }
            break;
            case CLICK:
            if(e.get_nom() == "QUIT" && e.get_parametre() == "LEFT")
            {
                delete _sceneActive;
                _sceneActive = NULL;
                _app->Close();
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
