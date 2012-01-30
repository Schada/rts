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
        /**
        * <------------------------------------------------------- Methodes Public ------------------------------------------------------->
        */

        /**
        * Constructeurs et Destructeur
        */
        Engine_Event(int scene, int type, std::string nom, std::string parametre);
        ~Engine_Event();

        /**
        * Accesseurs
        */
        int get_scene();
        int get_type();
        std::string get_nom();
        std::string get_parametre();

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
        * Variable indiquant quelle est la scene dans laquelle l'�v�nement du message c'est produit (pas la cible !)
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

        /**
        * Param�tre du message li� au type voir README.txt
        */
        std::string _parametre;

};

#endif //GAME_H

