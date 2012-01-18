#ifndef ENGINE_GRAPHICS_H
#define ENGINE_GRAPHICS_H

#include "Engine.h"

class Engine_Graphics : public Engine
{
    public:
        Engine_Graphics(Game* game);
        virtual ~Engine_Graphics();

        virtual void frame();


    protected:

        /**
        * Traitement d'un message, propre à chaque moteur.
        */
        virtual void process_event(Engine_Event& e);

        /**
        * Fonction "main" du Thread
        */
        virtual void Run();


};

#endif // ENGINE_GRAPHICS_H

