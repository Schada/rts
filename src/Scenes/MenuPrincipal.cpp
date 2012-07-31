#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(sf::RenderWindow* app) : Scene(app)
{

    _image = NULL;
    _imageFond = NULL;
    _fondEcran = NULL;
    _buttonPlay = NULL;
    _buttonQuit = NULL;

    _sound = NULL;
    _buffer = NULL;
    _music = NULL;

    _zone = NULL;

}

MenuPrincipal::~MenuPrincipal()
{
    _imageFond = NULL;
    _image = NULL;
    delete _fondEcran;

    delete _buttonPlay;
    delete _buttonQuit;

    delete _sound;
    _buffer = NULL;
    _music = NULL;
    delete _zone;
}

void MenuPrincipal::initGfx()
{
    int x = _app->GetWidth();
    int y = _app->GetHeight();
    sf::Color pixel;

    _image = _gi->get_contenu("Buttons");
    _imageFond = _gi->get_contenu("Fond");

    _fondEcran = new sf::Sprite();
    _buttonPlay = new sf::Sprite();
    _buttonQuit = new sf::Sprite();

    _fondEcran->SetImage(*_imageFond);
    _buttonPlay->SetImage(*_image);
    _buttonQuit->SetImage(*_image);

    pixel = _buttonPlay->GetPixel(0, 0);
    _image->CreateMaskFromColor(pixel);

    _buttonPlay->SetSubRect(sf::IntRect(0*_image->GetWidth()/2,2*_image->GetHeight()/3, 1*_image->GetWidth()/2,3*_image->GetHeight()/3));
    _buttonQuit->SetSubRect(sf::IntRect(0*_image->GetWidth()/2,1*_image->GetHeight()/3, 1*_image->GetWidth()/2,2*_image->GetHeight()/3));

    _fondEcran->SetPosition(0,0);
    _fondEcran->Resize(800,600);
    _buttonPlay->SetPosition(sf::Vector2f(x/2 - _image->GetWidth()/4, y/2 - _image->GetHeight()/3));
    _buttonQuit->SetPosition(sf::Vector2f(x/2 - _image->GetWidth()/4, y/2 ));

    //_zone = new ZoneTexte(_app, 0.f, 0.f, 100, 50, "Entrez un texte");

    _gfxInit = true;

}

void MenuPrincipal::initSon()
{
    _sound = new sf::Sound();
    _buffer = _gs->get_contenu("t");
    _sound->SetBuffer(*_buffer);
    _music = _gm->get_contenu("test");

    _sonInit = true;
}

void MenuPrincipal::initJeu()
{
    _jeuInit = true;
}

void MenuPrincipal::afficher()
{
    _app->Clear();
    _app->Draw(*_fondEcran);
    _app->Draw(*_buttonPlay);
    _app->Draw(*_buttonQuit);
    //_zone->afficher();
    _app->Display();
}

void MenuPrincipal::animation(std::string mess)
{
    /*if(mess == "MOUSEOVERPLAY")
    {
        _buttonPlay->SetSubRect(sf::IntRect(1*_image->GetWidth()/2,2*_image->GetHeight()/3, 2*_image->GetWidth()/2,3*_image->GetHeight()/3));

    }
    if(mess == "MOUSEOVERQUIT")
    {
        _buttonQuit->SetSubRect(sf::IntRect(1*_image->GetWidth()/2,1*_image->GetHeight()/3, 2*_image->GetWidth()/2,2*_image->GetHeight()/3));
    }
    if(mess == "MOUSEQUITQUIT")
    {
        _buttonQuit->SetSubRect(sf::IntRect(56,191,230,240));
    }
    if(mess == "MOUSEQUITPLAY")
    {
        _buttonPlay->SetSubRect(sf::IntRect(73,350, 193,398));
    }*/
}

float MenuPrincipal::jouerSon(std::string nom)
{
    _sound->Play();
    return _buffer->GetDuration();
}

void MenuPrincipal::jouerMusique(std::string nom)
{
    _music->Play();
}

void MenuPrincipal::stopperMusique()
{
    _music->Stop();
}

sf::Sprite* MenuPrincipal::get_sprite(std::string nom)
{
    if(nom == "Play")
    {
        return _buttonPlay;
    }
    else if(nom == "Quit")
    {
        return _buttonQuit;
    }
    else if(nom == "Zone")
    {
        return NULL;//_zone->get_sprite();
    }

    return NULL;
}

