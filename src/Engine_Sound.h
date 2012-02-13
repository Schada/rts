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
#include "Gestionnaire_Sons.h"
#include "Gestionnaire_Musiques.h"

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

        /**
        * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
        */
        /**
        * Pointeur sur le gestionnaire de sons du jeu.
        */
        Gestionnaire_Sons* _gs;
        Gestionnaire_Musiques* _gm;

    sf::Sound* _sound;
    sf::SoundBuffer* _buffer;
    sf::Music* _music;

};

#endif // ENGINE_SOUND_H
