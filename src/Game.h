#ifndef GAME_H
#define GAME_H

#include "Engine.h"
#include <iostream>
#include <SFML/Graphics.hpp>



class Game{
    public:
	Game();
	~Game();
	/**
	* Permet d'afficher à l'écran un menu principal.
	* @fixme
	*/
    void mainMenu();
    private:
	Engine* _engine1;
	Engine* _engine2;


};

#endif //GAME_H
