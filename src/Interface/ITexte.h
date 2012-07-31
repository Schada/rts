#ifndef ITEXTE_H
#define ITEXTE_H

#include "IElement.h"

class ITexte : public IElement
{
    public:
        ITexte(sf::RenderWindow* app, std::string nom);
        virtual ~ITexte();

        virtual std::string type();
    protected:
    private:
};

#endif // ITEXTE_H
