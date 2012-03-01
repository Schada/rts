#include "Entite_Active.h"

Entite_Active::Entite_Active(Entite_Schema* schema)
{

    _schema = schema;
    _sprite.SetImage(*(_schema->get_Image()));
    _sprite.SetPosition(50,50);
    _sprite.SetSubRect(sf::IntRect(0,0,50,50));
}

Entite_Active::~Entite_Active()
{
    _schema = NULL;
}

sf::Sprite* Entite_Active::get_Sprite()
{
    return &_sprite;
}
