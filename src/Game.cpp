#include "Game.h"

Game::Game()
{
    _engine1 = new Engine(this);
	_engine2 = new Engine(this);
}

Game::~Game()
{
    delete _engine1;
    delete _engine2;
}

void Game::test()
{
    Engine_Event *p0 = new Engine_Event(0);
    Engine_Event *p1 = new Engine_Event(1);
    Engine_Event *p2 = new Engine_Event(2);

    std::cout<<"Ouverture Threads"<<std::endl;
    _engine1->Launch();
    _engine2->Launch();

	_engine1->push_event(*p0);
	_engine2->push_event(*p1);
	_engine1->push_event(*p2);

}

void Game::fin()
{

    _engine1->finir();
    _engine2->finir();
    std::cout<<"Fermeture Threads"<<std::endl;
}

void Game::mainMenu()
{
    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Land of Martyrs");
    sf::Image image;
    sf::Sprite buttonPlay;
    sf::Sprite buttonQuit;

    if (!image.LoadFromFile("IMG_DOSSIER\\buttons.png"))
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
