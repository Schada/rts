/**
*   Auteur : Sept64
*   Classe : Scene Option
*   Role : Permet la Creation de la scene option dans le jeu
*/

#ifndef OPTIONS_H
#define OPTIONS_H

#include <SFML/Graphics.hpp>
#include "../Gfx/Gestionnaire_Images.h"
#include "../Son/Gestionnaire_Musiques.h"
#include "../Son/Gestionnaire_Sons.h"
#include <iostream>
#include "Scene.h"

class Options : public Scene
{
    public:

        Options(sf::RenderWindow* app);
        virtual ~Options();

        void run();
        void animation(std::string mess);

        float jouerSon(std::string nom);
        void jouerMusique(std::string nom);
        void stopperMusique();

        sf::Sprite* get_sprite(std::string nom);


        void initGfx();
        void initSon();
        void initJeu();

    protected:

        sf::RenderWindow* _app;
        Gestionnaire_Images* _gi;
        Gestionnaire_Sons* _gs;
        Gestionnaire_Musiques* _gm;

        bool _gfxInit;
        bool _sonInit;
        bool _jeuInit;

        sf::Clock _clock;
    private:

        sf::Image* _image;
        sf::Image* _imageFond;
        sf::Sprite* _fondEcran;
        sf::Sprite* _buttonPleinEcran;
        sf::Sprite* _buttonReturn;

        sf::Sound* _sound;
        sf::SoundBuffer* _buffer;
        sf::Music* _music;

};

#endif // OPTIONS_H
