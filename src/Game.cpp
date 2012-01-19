#include "Game.h"

Game::Game()
{
    _app = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Land of Martyrs");

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
                Engine_Event e("QUIT");
                _eng_gfx->push_event(e);
            }


        }
    }
    _eng_game->finir();
    _eng_gfx->finir();
    _eng_son->finir();
}
