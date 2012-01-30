/**
*   Auteur : Schada
*   Classe : Engine_Graphics
*   Role : Classe du Moteur Son
*          Gere les éléments Sonore du jeu
*/

#ifndef ENGINE_SOUND_H
#define ENGINE_SOUND_H

#include "Engine.h"
#include "Game.h"

class Engine_Sound : public Engine
{
    public:
        /**
        * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
        */

        /**
        * Constructeurs et Destructeur
        */
        Engine_Sound(Game* game, sf::RenderWindow* app, std::string nom);
        virtual ~Engine_Sound();

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

#endif // ENGINE_SOUND_H
