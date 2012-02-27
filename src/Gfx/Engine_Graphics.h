/**
*   Auteur : Schada
*   Classe : Engine_Graphics
*   Role : Classe du Moteur Graphique
*          Gere les éléments Graphiques du jeu
*/

#ifndef ENGINE_GRAPHICS_H
#define ENGINE_GRAPHICS_H

#include "../Base/Engine.h"
#include "../Scenes/Scene.h"
#include "../Scenes/Scene_MenuPrincipal.h"
#include "../Scenes/Scene_Jeu.h"
#include "Gestionnaire_Images.h"

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
        * Permet de paremetrer la nouvelle scene en fonction du moteur
        */
        void sceneChangee();

        /**
        * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
        */
        Gestionnaire_Images* _gi;

};

#endif // ENGINE_GRAPHICS_H

