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

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Game{
    public:
	Game();
	~Game();

	/**
	* Permet de demarrer le jeu
	*/
	void run();

	static std::string RecupValeurLigne(std::string lienFichier, std::string balise, std::string nomLigne);
    static bool VerifExistanceNom(std::string lienFichier, std::string nom, std::string balise);
    static bool VerifExistanceVal(std::string lienFichier, std::string nomLigne, std::string val, std::string balise);

    private:
	Engine_Game *_eng_game;
	Engine_Graphics *_eng_gfx;
	Engine_Sound *_eng_son;

	bool _encours;

	sf::RenderWindow *_app;


};

#endif //GAME_H
