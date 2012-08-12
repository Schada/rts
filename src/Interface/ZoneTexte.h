#ifndef ZONETEXTE_H
#define ZONETEXTE_H

#include "../Base/constantes.h"
#include "IBloquant.h"


class ZoneTexte : public IBloquant
{
    public:
        ZoneTexte(sf::RenderWindow* app, Scene* parent, std::string nom);
        virtual ~ZoneTexte();
        void action(sf::Event event);
        void modifTexte(char caractere);


        void afficherActif();
        bool verifActif(sf::Event event);

        std::string type();

    private:


};

#endif // ZONETEXTE_H



