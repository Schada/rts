#ifndef ZONETEXTE_H
#define ZONETEXTE_H

#include "../Base/constantes.h"
#include "IEBloquant.h"

class Core;

class ZoneTexte : public IEBloquant
{
    public:
        ZoneTexte(sf::RenderWindow* app, float posX, float posY, int sizeX, int sizeY);
        virtual ~ZoneTexte();

        void modifTexte(char caractere);

    private:


};

#endif // ZONETEXTE_H



