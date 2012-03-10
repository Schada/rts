/**
*   Auteur : Schada
*   Classe : Engine_Event
*   Role : Classe des messages échangés par les différents moteurs
*/

#ifndef ENGINE_EVENT_H
#define ENGINE_EVENT_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Engine_Event{
    public:
        /**
        * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
        */

        /**
        * Constructeurs et Destructeur
        */
        Engine_Event(int scene, int type, std::string nom, sf::Event* _event);
        Engine_Event(Engine_Event const& engine_event);
        ~Engine_Event();

        void changerEvent(int scene, int type, std::string nom, sf::Event* event);

        /**
        * Accesseurs
        */
        int get_scene();
        int get_type();
        std::string get_nom();
        sf::Event* get_event();

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
        * Variable indiquant quelle est la scene dans laquelle l'évènement du message c'est produit (pas la cible !)
        */
        int _scene;

        /**
        * Variable indiquant quelle est le type du message
        */
        int _type;

        /**
        * Nom du message
        */
        std::string _nom;

        sf::Event* _event;

};

#endif //GAME_H

