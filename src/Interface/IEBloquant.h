#ifndef IEBLOQUANT_H
#define IEBLOQUANT_H

#include "IElement.h"

class IEBloquant : public IElement
{
    public:
        IEBloquant(sf::RenderWindow* app, float posX, float posY, int sizeX, int sizeY);
        virtual ~IEBloquant();

        void setActif(bool actif);
        bool getActif() const;


    protected:

        bool _actif;
};

#endif // IEBLOQUANT_H
