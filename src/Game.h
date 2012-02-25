/**
*   Auteur : Schada
*   Classe : Game
*   Role : Classe Principale du Jeu
*          Gere les ressources du jeu
*/

#ifndef GAME_H
#define GAME_H

#include "constantes.h"
#include "Engine_Game.h"
#include "Engine_Graphics.h"
#include "Engine_Sound.h"
#include "Civilisation.h"

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Game{
    public:
        /**
        * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
        */

        /**
        * Constructeurs et Destructeur
        */
        Game();
        ~Game();

        /**
        * Permet de demarrer le jeu
        */
        void run();

        /**
        * Permet de recuperer la valeur contenu dans la ligne de nom "nomLigne" dans la balise "balise" du fichier à ladresse "lienFichier"
        */
        static std::string RecupValeurLigne(std::string lienFichier, std::string balise, std::string nomLigne);

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

    private:

        /**
        * <------------------------------------------------------- Methodes Private ------------------------------------------------------->
        */

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
        sf::RenderWindow *_app;

        Civilisation* _humain;


};

#endif //GAME_H
