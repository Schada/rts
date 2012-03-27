#include "ZoneTexte.h"
#include "../Base/Core.h"

ZoneTexte::ZoneTexte(sf::RenderWindow* app, float posX, float posY, int sizeX, int sizeY)
{
    _app = app;
    _actif = false;

    _sprite.SetColor(sf::Color(0, 255, 0, 128));
    _sprite.SetPosition(posX, posY);
    _sprite.SetSubRect(sf::IntRect(0, 0, sizeX, sizeY));


    if (!_font.LoadFromFile("arial.ttf", 50))
    {
        // Erreurr...
    }

    _text.SetText("");
    _text.SetFont(_font);
    _text.SetSize(20);
}

ZoneTexte::~ZoneTexte()
{
    _app = NULL;
}

void ZoneTexte::events_ZoneTexte()
{
    sf::Event Event;
    _actif = true;
    while (_actif)
    {
        // On lock le mutex avant de recuperer les events
        Core::win_mu->Lock();
        while (_app->GetEvent(Event))
        {
            // On unlock le mutex et on traite l'event recuperer en fonction de la scene
            Core::win_mu->Unlock();

             if(Event.Type == sf::Event::TextEntered)
             {
                _texte += (char)Event.Text.Unicode;

             }
             else if(Event.Type == sf::Event::MouseButtonPressed && Event.MouseButton.Button == sf::Mouse::Left)
             {
                if(!(Event.MouseButton.X > _sprite.GetPosition().x && Event.MouseButton.X < _sprite.GetPosition().x + _sprite.GetSize().x && Event.MouseButton.Y > _sprite.GetPosition().y && Event.MouseButton.Y < _sprite.GetPosition().y + _sprite.GetSize().y ))
                {
                    _actif = false;

                }
             }

            // On lock pour recuperer l'event au prochain tour de boucle
            Core::win_mu->Lock();
        }
        // On unlock dans le cas ou il n'y avait plus d'event
        Core::win_mu->Unlock();

    }
}

void ZoneTexte::afficher()
{
    _text.SetText(_texte);
    _app->Draw(_sprite);
    _app->Draw(_text);
}

sf::Sprite* ZoneTexte::get_sprite()
{
    return &_sprite;
}
