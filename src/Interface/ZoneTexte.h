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
        void modifTexte(sf::Event event);


        void afficherActif();
        bool verifActif(sf::Event event);

        std::string type();

        std::string getStock() const;

    private:
        std::string _stock;


};

#endif // ZONETEXTE_H



