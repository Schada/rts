/**
*   Auteur : Schada
*   Classe : Engine_Graphics
*   Role : Classe du Moteur Graphique
*          Gere les éléments Graphiques du jeu
*/

#ifndef ENGINE_GRAPHICS_H
#define ENGINE_GRAPHICS_H

#include "Engine.h"
#include "Scene.h"
#include "Scene_MenuPrincipal.h"
#include "Scene_Jeu.h"

class Engine_Graphics : public Engine
{
    public:
        Engine_Graphics(Game* game, sf::RenderWindow* app);
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

        Scene* _sceneActive;
        Gestionnaire_Images* _gi;
};

#endif // ENGINE_GRAPHICS_H

