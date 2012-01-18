#ifndef ENGINE_EVENT_H
#define ENGINE_EVENT_H

class Engine_Event{
    public:
	Engine_Event(int nb);
	~Engine_Event();

	int get_nb();

    private:
        int _nb;


};

#endif //GAME_H
