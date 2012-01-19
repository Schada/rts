#include "Game.h"

Game::Game()
{
    _eng_game = new Engine_Game(this);
	_eng_gfx = new Engine_Graphics(this);
	_eng_son = new Engine_Sound(this);

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
    _eng_game->finir();
    _eng_gfx->finir();
    _eng_son->finir();

    delete _eng_game;
    delete _eng_gfx;
    delete _eng_son;
}

void Game::mainMenu()
{
    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Land of Martyrs");
    sf::Image image;
    sf::Sprite buttonPlay;
    sf::Sprite buttonQuit;

    std::string lien = IMG_DOSSIER;
    lien = lien + "buttons.png";

    if (!image.LoadFromFile(lien.c_str()))
    {
        std::cout<<"Erreur durant le chargement de l'image"<<std::endl;
    }
    else
    {
        buttonPlay.SetImage(image);
        buttonQuit.SetImage(image);
    }
    buttonPlay.SetSubRect(sf::IntRect(0,0,150,80));
    buttonQuit.SetSubRect(sf::IntRect(40,0,150,65));

    buttonPlay.SetPosition(sf::Vector2f(0 ,0));
    buttonQuit.SetPosition(sf::Vector2f(120 ,120));

    while (app.IsOpened())
    {
        sf::Event event;
        while (app.GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
                app.Close();
        }
        app.Draw(buttonPlay);
        app.Draw(buttonQuit);
        app.Clear();
        app.Display();
    }
}
