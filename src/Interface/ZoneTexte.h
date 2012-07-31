#ifndef ZONETEXTE_H
#define ZONETEXTE_H

#include "../Base/constantes.h"
#include "IElement.h"

class Core;

class ZoneTexte : public IElement
{
    public:
        ZoneTexte(sf::RenderWindow* app, std::string nom);
        virtual ~ZoneTexte();
        void action(void* paramatre);
        void modifTexte(char caractere);

    private:


};

#endif // ZONETEXTE_H



