#include "Game.h"

Game::Game()
{}

Game::~Game()
{}

void mainMenu()
{
    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Land of Martyrs");
    sf::Image image;
    sf::Sprite sprite;

    if (!image.LoadFromFile("IMG_DOSSIER\\buttons.png"))
    {
        std::cout<<"Erreur durant le chargement de l'image"<<std::endl;
    }
    else
{
    sprite.SetImage(image);
}
    while (app.IsOpened())
    {
        sf::Event event;
        while (app.GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
                app.Close();
        }
        app.Draw(sprite);
        app.Clear();
        app.Display();
    }
}
