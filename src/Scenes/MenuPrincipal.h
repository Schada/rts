/**
*   Auteur : Schada, Sept
*   Classe : Scene_MenuPrincipal
*   Role : Permet la Creation de la Scene MenuPrincipal
*/

#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include "Scene.h"
#include "../Base/constantes.h"
#include <iostream>
#include <string>

class MenuPrincipal : public Scene
{
    public:
        MenuPrincipal(sf::RenderWindow* app);
        ~MenuPrincipal();

        void run();
        /**
        *   Permet de gérer les animations du menu principal en fonction des messages passées en paramètres.
        */
        void animation(std::string mess);

        float jouerSon(std::string nom);
        void jouerMusique(std::string nom);
        void stopperMusique();

        sf::Sprite* get_sprite(std::string nom);

        void initGfx();
        void initSon();
        void initJeu();

    private:
        sf::Image* _image;
        sf::Image* _imageFond;
        sf::Sprite* _fondEcran;
        sf::Sprite* _buttonPlay;
        sf::Sprite* _buttonQuit;

        sf::Sound* _sound;
        sf::SoundBuffer* _buffer;
        sf::Music* _music;


};

#endif // MENUPRINCIPAL_H

