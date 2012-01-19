/**
*   Auteur : Schada
*   Classe : Engine (abstraite)
*   Role : Classe Générique des Moteurs
*/

#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/System.hpp>
#include <queue>
#include <iostream>
#include "Engine_Event.h"


class Engine_Game;
class Engine_Graphics;
class Engine_Sound;
class Game;

class Engine : public sf::Thread
{
    public:
        Engine(Game* game);
        virtual ~Engine();
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

        /**
        * Permet de lancer un Thread
        */
        void lancer();

        /**
        * Permet de terminer un Thread
        */
        void finir();

        /**
        * Permet l'envoit aux différents engines
        */
        void send_message_to_graphics(Engine_Event& e);
        void send_message_to_game(Engine_Event& e);
        void send_message_to_sound(Engine_Event& e);

        /**
        * Permet de relier les Engines entre eux
        */
        void attach_engine_game(Engine_Game* eng_game);
        void attach_engine_graphics(Engine_Graphics* eng_gfx);
        void attach_engine_sound(Engine_Sound* eng_son);


    protected:

        /**
        * Liste des différents Engines
        */
        Engine_Game *_eng_game;
        Engine_Graphics *_eng_gfx;
        Engine_Sound *_eng_son;

        /**
        * Traitement d'un message, propre à chaque moteur.
        */
        virtual void process_event(Engine_Event& e) = 0;

        /**
        * Fonction "main" du Thread
        */
        virtual void Run() = 0;

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
        bool _encours;


};

#endif // ENGINE_H
