/**
*   Auteur : Schada
*   Classe : Core
*   Role : Classe Principale du Jeu
*          Gere les entrées clavier du jeu
*/

#ifndef CORE_H
#define CORE_H

#include "constantes.h"
#include "../Scenes/Scene.h"
#include "../Scenes/MenuPrincipal.h"
#include "../Scenes/Jeu.h"
#include "../Scenes/Chargement.h"
#include "../Scenes/Options.h"
#include "../Jeu/Engine_Game.h"
#include "../Gfx/Engine_Graphics.h"
#include "../Son/Engine_Sound.h"
#include "../Ressources/Civilisation.h"

#include <iostream>
#include <string>

class Core
{
    public:
        /**
        * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
        */

        /**
        * Constructeurs et Destructeur
        */
        Core();
        ~Core();

        /**
        * Recupere les evenements et appel les fonctions gerant les evenements en fonction de la scene actuelle
        */
        void run();

        /**
        * Permet de changer la scene actuelle du jeu
        */
        void changerScene(int scene, bool all);

        /**
        * Permet de recuperer un pointeur sur la scene actuelle
        */
        Scene* get_Scene();

        /**
        * Permet de recuperer le numero de la scene actuelle
        */
        int get_numeroScene();

        /**
        * Permet de recuperer la valeur contenu dans la ligne de nom "nomLigne" dans la balise "balise" du fichier à ladresse "lienFichier"
        */
        static std::string RecupValeurLigne(std::string lienFichier, std::string balise, std::string nomLigne);

        /**
        * Permet de recuperer la valeur contenu à la ligne numeroLigne dans la balise "balise" du fichier à ladresse "lienFichier"
        */
        static std::string RecupValeurNumeroLigne(std::string lienFichier, std::string balise, int numeroLigne);

        /**
        * Renvoi True si le nom "nom" de la balise "balise" dans le fichier à l'adresse "lienFichier" existe
        */
        static bool VerifExistanceNom(std::string lienFichier, std::string nom, std::string balise);

        /**
        * Indique si une ligne "nomLigne" dans la balise "balise" a pour valeur "val" dans le fichier à l'adresse "lienFchier"
        * Renvoit true si la valeur existe
        * Renvoit false pour tout les autres cas (ligne, balise introuvable ...)
        */
        static bool VerifExistanceVal(std::string lienFichier, std::string nomLigne, std::string val, std::string balise);

        /**
        * <------------------------------------------------------- Attributs Public ------------------------------------------------------->
        */

        /**
        * Attibuts static contenant des informations sur le mod utilise
        */
        static const std::string dossierMod;
        static const std::string fichierMod;


        /**
        * Mutex de _app
        */
        static sf::Mutex* win_mu;


    private:

        /**
        * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
        */

        /**
        * Les differentes fonctions gerant les evenements en fonction de la scene
        */
        void events_MenuPrincipal();
        void events_Jeu();
        void events_Chargement();
        void events_Options();
        void events_All();


        /**
        * Permet d'envoyer l'evenement en cours de traitement a tout les moteurs
        */
        void envoiMultiple();

        /**
        * Permet d'attendre que tous les moteurs n'ont plus acces a la scene actuelle pour proceder au changement de scene
        */
        void attendreFinScene();

        /**
        * <------------------------------------------------------- Attributs Private ------------------------------------------------------->
        */

        /**
        * Liste des pointeurs sur les différents moteurs
        */
        Engine_Game *_eng_game;
        Engine_Graphics *_eng_gfx;
        Engine_Sound *_eng_son;

        /**
        * Pointeur sur la fenetre de rendu
        */
        sf::RenderWindow* _app;

        /**
        * Contient l'evenement sfml en cours de traitement
        */
        sf::Event _event;

        /**
        * Contient l'evenement du jeu
        */
        Engine_Event _eng_event;

        /**
        * Pointeur sur la scene actuelle
        */
        Scene* _scene;

        /**
        * Numero de la scene actuelle
        */
        int _numeroScene;
};

#endif //CORE_H
