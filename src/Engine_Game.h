/**
*   Auteur : Schada
*   Classe : Engine_Game
*   Role : Classe du Moteur de Jeu
*          Gere les différents éléments du jeu
*/

#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include "Engine.h"

class Engine_Game : public Engine
{
    public:
        /**
        * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
        */

        /**
        * Constructeurs et Destructeur
        */
        Engine_Game(Game* game, sf::RenderWindow* app, std::string nom);
        virtual ~Engine_Game();

        /**
        * Traitement propre au moteur.
        */
        virtual void frame();

        /**
        * <------------------------------------------------------- Attributs Public ------------------------------------------------------->
        */

    private:

        /**
        * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
        */

        /**
        * Fonction "main" du Thread
        */
        virtual void Run();

        /**
        * Permet de regrouper le traitement des messages par scene
        */
        void event_MenuPrincipal(Engine_Event& e);
        void event_Chargement(Engine_Event& e);
        void event_Jeu(Engine_Event& e);

        /**
        * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
        */


};

#endif // ENGINE_GAME_H
