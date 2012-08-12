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
#include "../Scenes/Scene_Globale.h"
#include "../Scenes/Scene_Locale.h"
#include "../Jeu/Engine_Game.h"
#include "../Gfx/Engine_Graphics.h"
#include "../Son/Engine_Sound.h"
#include "../Ressources/Civilisation.h"

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

        void changerScene(std::string nom);

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

        static void RecupValeurLigne(std::string lienFichier, std::string balise, std::string nomLigne, std::string** pointeur);

        /**
        * Permet de recuperer la valeur contenu à la ligne numeroLigne dans la balise "balise" du fichier à ladresse "lienFichier"
        */

        /// Obsolète voir la fonction DeplacementFichier
        //static std::string RecupValeurNumeroLigne(std::string lienFichier, std::string balise, int numeroLigne);

        //static void RecupValeurNumeroLigne(std::string lienFichier, std::string balise, int numeroLigne, std::string** pointeur);

        /**
        * Permet de se positionner au debut de la balise "balise" dans le fichier envoyer en parametre
        * Cette fonction remplace les fonctions RecupValeurNumeroLigne après l'appel de la fonction faire des getline() jusqu'a trouver la balise [Fin]
        * Les fonctions RecupValeurNumeroLigne etait trop lourdes car elle ouvraient et fermaient le fichier a chaque utilisation.
        * En utilisant cette fonction ne pas oublier d'ouvrir et fermer le fichier après utilisation.
        */
        static bool DeplacementFichier(Struct_File* sfile, std::string balise);

        /**
        * Renvoi True si le nom "nom" de la balise "balise" dans le fichier à l'adresse "lienFichier" existe
        */
        static bool VerifExistanceNom(std::string lienFichier, std::string balise, std::string nom);

        /**
        * Indique si une ligne "nomLigne" dans la balise "balise" a pour valeur "val" dans le fichier à l'adresse "lienFchier"
        * Renvoit true si la valeur existe
        * Renvoit false pour tout les autres cas (ligne, balise introuvable ...)
        */
        static bool VerifExistanceVal(std::string lienFichier, std::string balise, std::string nomLigne, std::string val);


        static Scene* creerScene(sf::RenderWindow* app, std::string nom, Scene_Locale* console);

        /**
        * Permet de decouper le texte en un vector de std::string séparé à l'origine par des espaces.
        */
        static void decouperTexte(std::string texte, std::vector < std::string > * tab, size_t nb = 0);


        /**
        * <------------------------------------------------------- Attributs Public ------------------------------------------------------->
        */

        /**
        * Attibuts static contenant des informations sur le mod utilise
        */
        static const std::string dossierMod;
        static const std::string fichierMod;

        static const std::string dossierScene;

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

        void events(std::string action);


        /**
        * Permet d'envoyer l'evenement en cours de traitement a tout les moteurs
        */
        void envoiMultiple();

        /**
        * Permet d'attendre que tous les moteurs n'ont plus acces a la scene actuelle pour proceder au changement de scene
        */
        void attendreFinScene();

        /**
        * Permet de créer la console du jeu
        */
        void creerConsole();

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

        /**
        * Pointeur sur la Console
        */
        Scene_Locale* _console;
};

#endif //CORE_H
