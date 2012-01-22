#include "Game.h"

Game::Game()
{
    _app = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Land of Martyrs");
    _app->SetFramerateLimit(60); // Limite la fen�tre � 60 images par seconde
    _eng_game = new Engine_Game(this, _app);
	_eng_gfx = new Engine_Graphics(this, _app);
	_eng_son = new Engine_Sound(this, _app);

	_eng_game->attach_engine_graphics(_eng_gfx);
	_eng_game->attach_engine_sound(_eng_son);

	_eng_gfx->attach_engine_game(_eng_game);
	_eng_gfx->attach_engine_sound(_eng_son);

	_eng_son->attach_engine_game(_eng_game);
	_eng_son->attach_engine_graphics(_eng_gfx);

	_eng_game->Launch();
	_eng_gfx->Launch();
	_eng_son->Launch();

	//Permet de syncroniser les moteurs entre eux

	_eng_game->lancer();
	_eng_gfx->lancer();
	_eng_son->lancer();
}

Game::~Game()
{
    delete _eng_game;
    delete _eng_gfx;
    delete _eng_son;
    delete _app;
}

void Game::run()
{
    _app->SetActive(false);
    while (_app->IsOpened())
    {
        sf::Event event;
        while (_app->GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
            {
                Engine_Event e(MENU_PRINCIPAL, CLICK, "QUIT", "LEFT");
                _eng_gfx->push_event(e);
                _eng_game->push_event(e);
                _eng_son->push_event(e);
                _eng_game->Wait();
                _eng_gfx->Wait();
                _eng_son->Wait();
            }
            else if (event.Type == sf::Event::MouseMoved)
            {
                int xPlay = (*_app).GetWidth()/2-50;
                int yPlay = (*_app).GetHeight()/2-50;
                int xQuit = (*_app).GetWidth()/2-50;
                int yQuit = (*_app).GetHeight()/2-50+150;

                int MouseX = event.MouseMove.X;
                int MouseY = event.MouseMove.Y;

                if(MouseX > xPlay && MouseX < (xPlay + 150) && MouseY > yPlay && MouseY < (yPlay + 60) )
                {
                    Engine_Event e(MENU_PRINCIPAL, MOUSE, "PLAY", "IN");
                    _eng_gfx->push_event(e);
                }
                else{
                    Engine_Event e(MENU_PRINCIPAL, MOUSE, "PLAY", "OUT");
                    _eng_gfx->push_event(e);
                }
                if(MouseX > xQuit && MouseX < (xQuit + 150) && MouseY > yQuit && MouseY < (yQuit+ 60) )
                {
                    Engine_Event e(MENU_PRINCIPAL, MOUSE, "QUIT", "IN");
                    _eng_gfx->push_event(e);
                }
                else
                {
                    Engine_Event e(MENU_PRINCIPAL, MOUSE, "QUIT", "OUT");
                    _eng_gfx->push_event(e);
                }
            }
        }
    }
}
