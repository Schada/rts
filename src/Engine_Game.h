#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include "Engine.h"

class Engine_Game : public Engine
{
    public:
        Engine_Game(Game* game);
        virtual ~Engine_Game();

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

#endif // ENGINE_GAME_H
