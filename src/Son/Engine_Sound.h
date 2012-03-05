/**
*   Auteur : Schada
*   Classe : Engine_Graphics
*   Role : Classe du Moteur Son
*          Gere les éléments Sonore du jeu
*/

#ifndef ENGINE_SOUND_H
#define ENGINE_SOUND_H

#include "../Base/Engine.h"
#include "../Base/Game.h"
#include "../Son/Gestionnaire_Sons.h"
#include "../Son/Gestionnaire_Musiques.h"

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
        ~Engine_Sound();

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
        void event_All(Engine_Event& e);

        /**
        * Permet de paremetrer la nouvelle scene en fonction du moteur
        */
        void sceneChangee();

        /**
        * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
        */

        Gestionnaire_Musiques* _gm;
        Gestionnaire_Sons* _gs;


};

#endif // ENGINE_SOUND_H
