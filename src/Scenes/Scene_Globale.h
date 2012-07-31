#ifndef SCENE_GLOBALE_H
#define SCENE_GLOBALE_H

#include "Scene.h"
#include "Scene_Locale.h"
#include <SFML/Graphics.hpp>


class Scene_Globale : public Scene
{
    public:
        Scene_Globale(sf::RenderWindow* app, Scene_Locale* console, std::string nom, std::string fond);
        virtual ~Scene_Globale();

    /**
    * Permet d'afficher la scene
    */
    virtual void afficher();

    protected:
        Scene_Locale* _console;
        std::vector < Scene_Locale* > _scenes;
    private:
};

#endif // SCENE_GLOBALE_H
