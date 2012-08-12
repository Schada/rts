#ifndef ITEXTE_H
#define ITEXTE_H

#include "IElement.h"

class ITexte : public IElement
{
    public:
        ITexte(sf::RenderWindow* app, Scene* parent, std::string nom);
        virtual ~ITexte();

        std::string type();

        bool verifAction(sf::Event event);
    protected:
    private:
};

#endif // ITEXTE_H
