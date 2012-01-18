#include "Game.h"

Game::Game()
{}

Game::~Game()
{}

void mainMenu()
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
