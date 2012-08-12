#ifndef SCENE_LOCALE_H
#define SCENE_LOCALE_H

#include "Scene.h"

class Scene_Locale : public Scene
{
    public:
        Scene_Locale(sf::RenderWindow* app, std::string nom, std::string fond, bool deplacer, bool tete);
        virtual ~Scene_Locale();

    /**
    * Permet d'afficher la scene
    */
    virtual void afficher();

    protected:
        bool _deplacer;
        bool _tete;
    private:
};

#endif // SCENE_LOCALE_H
