/**
*   Auteur : Schada
*   Classe : Engine_Graphics
*   Role : Classe du Moteur Son
*          Gere les �l�ments Sonore du jeu
*/

#ifndef ENGINE_SOUND_H
#define ENGINE_SOUND_H

#include "Engine.h"
#include "Game.h"

class Engine_Sound : public Engine
{
    public:
        Engine_Sound(Game* game, sf::RenderWindow* app);
        virtual ~Engine_Sound();

        virtual void frame();


    protected:

        /**
        * Traitement d'un message, propre � chaque moteur.
        */
        virtual void process_event(Engine_Event& e);

        /**
        * Fonction "main" du Thread
        */
        virtual void Run();


};

#endif // ENGINE_SOUND_H
