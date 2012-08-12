#ifndef IBLOQUANT_H
#define IBLOQUANT_H

#include "IElement.h"

class Core;

class IBloquant : public IElement
{
    public:
        IBloquant(sf::RenderWindow* app, Scene* parent, std::string nom);
        virtual ~IBloquant();

        virtual void action(sf::Event event) = 0;
        virtual void afficherActif() = 0;
        virtual bool verifActif(sf::Event event) = 0;

        virtual std::string type() = 0;

        bool verifAction(sf::Event event);
    protected:
    private:
};

#endif // IBLOQUANT_H
