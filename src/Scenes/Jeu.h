#ifndef JEU_H
#define JEU_H

#include "Scene.h"
#include "../Ressources/Civilisation.h"

class Jeu : public Scene
{
    public:
        Jeu(sf::RenderWindow* app);
        virtual ~Jeu();

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
        sf::Font MyFont;
        sf::String Text;

        Gestionnaire_Entites* _schemas;
        Civilisation* _humain;
};

#endif // JEU_H
