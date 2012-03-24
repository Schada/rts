#include "Options.h"


Options::Options(sf::RenderWindow* app) : Scene(app)
{
        _image = NULL;
        _imageFond = NULL;
        _fondEcran = NULL;
        _buttonPleinEcran = NULL;
        _buttonReturn = NULL;

        _sound = NULL;
        _buffer = NULL;
        _music = NULL;
}

Options::~Options()
{
    _imageFond = NULL;
    _image = NULL;
    delete _fondEcran;

    delete _buttonPleinEcran;
    delete _buttonReturn;

    delete _sound;
    _buffer = NULL;
    _music = NULL;
}

void Options::run()
{

}

void Options::animation(std::string mess)
{

}

float Options::jouerSon(std::string nom)
{
 return 0;
}

void Options::jouerMusique(std::string nom)
{

}

void Options::stopperMusique()
{

}

sf::Sprite* Options::get_sprite(std::string nom)
{
   /* if(nom == "CASE")
    {
        return _CASEON;
    }
    else if(nom == "Quit")
    {
        return _QUIT;
    }*/
    return NULL;
}

void Options::initGfx()
{

}

void Options::initSon()
{

}

void Options::initJeu()
{

}
