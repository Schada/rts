#include "Scene_Options.h"


Scene_Options::Scene_Options(sf::RenderWindow* app) : Scene(app)
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

Scene_Options::~Scene_Options()
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

void Scene_Options::set_gi(Gestionnaire_Images* gi)
{

}

void Scene_Options::set_gm(Gestionnaire_Musiques* gm)
{
    _gm = gm;
}

void Scene_Options::set_gs(Gestionnaire_Sons* gs)
{
    _gs = gs;
}

bool Scene_Options::isInit()
{
    if(_gfxInit)
    {
        if(_sonInit)
        {
            if(_jeuInit)
            {
                return true;
            }
        }
    }

    return false;
}

float Scene_Options::time()
{
    return floor(_clock.GetElapsedTime());
}

void Scene_Options::run()
{

}

void Scene_Options::animation(std::string mess)
{

}

float Scene_Options::jouerSon(std::string nom)
{
 return 0;
}

void Scene_Options::jouerMusique(std::string nom)
{

}

void Scene_Options::stopperMusique()
{

}

sf::Sprite* Scene_Options::get_sprite(std::string nom)
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

void Scene_Options::initGfx()
{

}

void Scene_Options::initSon()
{

}

void Scene_Options::initJeu()
{

}
