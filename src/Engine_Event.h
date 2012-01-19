/**
*   Auteur : Schada
*   Classe : Engine_Event
*   Role : Classe des messages échangés par les différents moteurs
*/

#ifndef ENGINE_EVENT_H
#define ENGINE_EVENT_H

#include <string>

class Engine_Event{
    public:
	Engine_Event(std::string type, std::string nom);
	~Engine_Event();

	std::string get_scene();
	std::string get_type();
	std::string get_nom();
	std::string get_parametre();

    private:
        std::string _scene;
        std::string _type;
        std::string _nom;
        std::string _parametre;

};

#endif //GAME_H
