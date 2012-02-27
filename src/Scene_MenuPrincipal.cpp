#include "Scene_MenuPrincipal.h"

Scene_MenuPrincipal::Scene_MenuPrincipal(sf::RenderWindow* app, Gestionnaire_Images* gi, Gestionnaire_Musiques* gm, Gestionnaire_Sons* gs) : Scene(app, gi, gm, gs)
{
    int x, y;

    _sound = new sf::Sound();
    _buffer = NULL;
    _music = NULL;
    _fondEcran = new sf::Sprite();

    x = _app->GetWidth();
    y = _app->GetHeight();

    _image = *(_gi->get_contenu("Buttons"));
    _imageFond = *(_gi ->get_contenu("Fond"));

    _fondEcran->SetImage(_imageFond);
    _buttonPlay.SetImage(_image);
    _buttonQuit.SetImage(_image);

    sf::Color pixel = _buttonPlay.GetPixel(0, 0);
    _image.CreateMaskFromColor(pixel);

    _buttonPlay.SetSubRect(sf::IntRect(0*_image.GetWidth()/2,2*_image.GetHeight()/3, 1*_image.GetWidth()/2,3*_image.GetHeight()/3));
    _buttonQuit.SetSubRect(sf::IntRect(0*_image.GetWidth()/2,1*_image.GetHeight()/3, 1*_image.GetWidth()/2,2*_image.GetHeight()/3));

    _fondEcran->SetPosition(0,0);
    _fondEcran->Resize(800,600);
    _buttonPlay.SetPosition(sf::Vector2f(x/2 - _image.GetWidth()/4, y/2 - _image.GetHeight()/3));
    _buttonQuit.SetPosition(sf::Vector2f(x/2 - _image.GetWidth()/4, y/2 ));

}

Scene_MenuPrincipal::~Scene_MenuPrincipal()
{
    delete _sound;
    _buffer = NULL;
    _music = NULL;
    delete _fondEcran;
}

void Scene_MenuPrincipal::run()
{
    _app->Clear();
    _app->Draw(*_fondEcran);
    _app->Draw(_buttonPlay);
    _app->Draw(_buttonQuit);
    _app->Display();
}

void Scene_MenuPrincipal::animation(std::string mess)
{
    if(mess == "MOUSEOVERPLAY")
    {
        _buttonPlay.SetSubRect(sf::IntRect(1*_image.GetWidth()/2,2*_image.GetHeight()/3, 2*_image.GetWidth()/2,3*_image.GetHeight()/3));

    }
    if(mess == "MOUSEOVERQUIT")
    {
        _buttonQuit.SetSubRect(sf::IntRect(1*_image.GetWidth()/2,1*_image.GetHeight()/3, 2*_image.GetWidth()/2,2*_image.GetHeight()/3));
    }
    if(mess == "MOUSEQUITQUIT")
    {
        _buttonQuit.SetSubRect(sf::IntRect(56,191,230,240));
    }
    if(mess == "MOUSEQUITPLAY")
    {
        _buttonPlay.SetSubRect(sf::IntRect(73,350, 193,398));
    }
    if(mess == "MOUSECLICKPLAY")
    {

    }
}

float Scene_MenuPrincipal::jouerSon(std::string)
{
    _buffer = (_gs->get_contenu("t"));
    _sound->SetBuffer(*_buffer);
    _sound->Play();
    return _buffer->GetDuration();
}

void Scene_MenuPrincipal::jouerMusique(std::string)
{
    _music = _gm->get_contenu("test");
    _music->Play();

}

void Scene_MenuPrincipal::stopperMusique()
{
    _music->Stop();
}

sf::Sprite Scene_MenuPrincipal::get_sprite(std::string nom)
{
    if(nom == "Play")
    {
        return _buttonPlay;
    }
    return _buttonQuit;

}

void Scene_MenuPrincipal::test()
{
    std::cout << "OK" << std::endl;
}
