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
        /**
        * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
        */

        /**
        * Constructeurs et Destructeur
        */
        Engine_Graphics(Game* game, sf::RenderWindow* app, std::string nom);
        ~Engine_Graphics();

        /**
        * Traitement propre au moteur.
        */
        void frame();

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
        void Run();

        /**
        * Permet de regrouper le traitement des messages par scene
        */
        void event_MenuPrincipal(Engine_Event& e);
        void event_Chargement(Engine_Event& e);
        void event_Jeu(Engine_Event& e);

        /**
        * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
        */

        /**
        * Pointeur sur la scene active
        */
        Scene* _sceneActive;
        /**
        * Pointeur sur le gestionnaire d'images du jeu.
        */
        Gestionnaire_Images* _gi;
        /**
        * Pointeur sur le gestionnaire de sons du jeu.
        */
        Gestionnaire_Sons* _gs;
};

#endif // ENGINE_GRAPHICS_H

