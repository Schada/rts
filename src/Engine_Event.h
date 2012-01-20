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
	Engine_Event(int scene, int type, std::string nom, std::string parametre);
	~Engine_Event();

	int get_scene();
	int get_type();
	std::string get_nom();
	std::string get_parametre();

    private:
        int _scene;
        int _type;
        std::string _nom;
        std::string _parametre;

};

#endif //GAME_H

