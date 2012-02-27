/**
*   Auteur : Schada
*   Classe : Engine (abstraite)
*   Role : Classe Générique des Moteurs
*/

#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <queue>
#include <iostream>
#include "constantes.h"
#include "Engine_Event.h"
#include "Scene.h"


class Engine_Game;
class Engine_Graphics;
class Engine_Sound;
class Game;

class Engine : public sf::Thread
{
    public:

        /**
        * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
        */

        /**
        * Constructeurs et Destructeur
        */
        Engine(Game* game, sf::RenderWindow* app, std::string nom);
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
        * Permet l'envoi aux différents moteurs
        */
        void send_message_to_graphics(Engine_Event& e);
        void send_message_to_game(Engine_Event& e);
        void send_message_to_sound(Engine_Event& e);

        /**
        * Permet de relier les moteurs entre eux
        */
        void attach_engine_game(Engine_Game* eng_game);
        void attach_engine_graphics(Engine_Graphics* eng_gfx);
        void attach_engine_sound(Engine_Sound* eng_son);

        /**
        * Permet de modifier la scene active
        */
        void changerSceneActive(Scene* scene);

        /**
        * <------------------------------------------------------- Attributs Public ------------------------------------------------------->
        */


    protected:

        /**
        * <------------------------------------------------------- Methodes Protected ------------------------------------------------------->
        */

        /**
        * Traitement d'un message
        */
        void process_event(Engine_Event& e);

        /**
        * Fonction "main" du Thread
        */
        virtual void Run() = 0;

        /**
        * Permet de regrouper le traitement des messages par scene
        */
        virtual void event_MenuPrincipal(Engine_Event& e) = 0;
        virtual void event_Chargement(Engine_Event& e) = 0;
        virtual void event_Jeu(Engine_Event& e) = 0;
        virtual void event_All(Engine_Event& e);

        /**
        * <------------------------------------------------------- Attributs Protected ------------------------------------------------------->
        */

        /**
        * Nom du moteur
        */
        std::string _nom;

        /**
        * Pointeur sur la fenetre de rendu
        */
        sf::RenderWindow *_app;

        /**
        * Liste des différents moteurs
        */
        Engine_Game *_eng_game;
        Engine_Graphics *_eng_gfx;
        Engine_Sound *_eng_son;

        /**
        * Pointeur vers l'objet parent
        */
        Game *_parent;

        /**
        * File des messages à traiter
        */
        std::queue< Engine_Event > _events_queue;

        /**
        * Booleen pour savoir si le thread doit se terminer
        */
        bool _encours;

        /**
        * Pointeur sur la scene active
        */
        Scene* _sceneActive;

};

#endif // ENGINE_H
