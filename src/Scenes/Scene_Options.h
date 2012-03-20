/**
*   Auteur : Sept64
*   Classe : Scene Option
*   Role : Permet la Creation de la scene option dans le jeu
*/

#ifndef SCENE_OPTION_H
#define SCENE_OPTION_H

#include <SFML/Graphics.hpp>
#include "../Gfx/Gestionnaire_Images.h"
#include "../Son/Gestionnaire_Musiques.h"
#include "../Son/Gestionnaire_Sons.h"
#include <iostream>
#include "Scene.h"

class Scene_Options : public Scene
{
    public:

        Scene_Options(sf::RenderWindow* app);
        virtual ~Scene_Options();

        void run();
        void animation(std::string mess);

        float jouerSon(std::string nom);
        void jouerMusique(std::string nom);
        void stopperMusique();

        sf::Sprite* get_sprite(std::string nom);

        void set_gi(Gestionnaire_Images* gi);
        void set_gm(Gestionnaire_Musiques* gm);
        void set_gs(Gestionnaire_Sons* gs);

        void initGfx();
        void initSon();
        void initJeu();
        bool isInit();

        float time();

    protected:

        sf::RenderWindow* _app;
        Gestionnaire_Images* _gi;
        Gestionnaire_Sons* _gs;
        Gestionnaire_Musiques* _gm;

        bool _gfxInit;
        bool _sonInit;
        bool _jeuInit;

        sf::Clock _clock;

};

#endif // SCENE_H_OPTION
