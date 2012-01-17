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

        // accepter les messages des autres moteurs
        void push_event(Engine_Event& e);

        // traite la file des messages
        void process_queue();

        // traitement propre � chaque moteur
        virtual void frame() = 0;
    protected:
        //Pointeur vers l'objet parent
        Game *_parent;

        //file des messages � traiter
        std::queue< Engine_Event > _events_queue;

        //// traitement d'un message, propre � chaque moteur
        virtual void _process_event(Engine_Event&) = 0;

};

#endif // ENGINE_H
