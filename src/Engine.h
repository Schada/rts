#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/System.hpp>
#include <queue>
#include <iostream>
#include "Engine_Event.h"

class Game;

class Engine : public sf::Thread
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
        //virtual void frame() = 0;

        /**
        * Permet de terminer un Thread
        */
        void finir();

    protected:
        /**
        * Traitement d'un message, propre à chaque moteur.
        */
        virtual void process_event(Engine_Event& e);

        /**
        * Fonction "main" du Thread
        */
        virtual void Run();

        /**
        * Pointeur vers l'objet parent.
        */
        Game *_parent;
        /**
        * File des messages à traiter.
        */
        std::queue< Engine_Event > _events_queue;

        /**
        * Booleen pour savoir si le thread doit se terminer
        */
        bool encours;


};

#endif // ENGINE_H
