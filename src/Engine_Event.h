/**
*   Auteur : Schada
*   Classe : Engine_Event
*   Role : Classe des messages �chang�s par les diff�rents moteurs
*/

#ifndef ENGINE_EVENT_H
#define ENGINE_EVENT_H

#include <string>

class Engine_Event{
    public:
	Engine_Event(std::string nb);
	~Engine_Event();

	std::string get_nb();

    private:
        std::string _nb;


};

#endif //GAME_H
