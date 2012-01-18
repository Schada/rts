#ifndef ENGINE_H
#define ENGINE_H

#include <queue>
#include "Engine_Event.h"

class Game;

class Engine
{
    public:
        Engine(Game* game);
        ~Engine();
        /**
        * Accepter les messages des autres moteurs.
        */
        void push_event(Engine_Event& e);
        /**
        * Traite la file des messages.
        */
        void process_queue();
        /**
        * Traitement propre à chaque moteur.
        */
        virtual void frame() = 0;

    protected:
        /**
        * Pointeur vers l'objet parent.
        */
        Game *_parent;
        /**
        * File des messages à traiter.
        */
        std::queue< Engine_Event > _events_queue;
        /**
        * Traitement d'un message, propre à chaque moteur.
        */
        virtual void _process_event(Engine_Event&) = 0;

};

#endif // ENGINE_H
