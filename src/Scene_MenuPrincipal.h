/**
*   Auteur : Schada
*   Classe : Scene_MenuPrincipal
*   Role : Permet la Creation de la Scene MenuPrincipal
*/

#ifndef SCENE_MENUPRINCIPAL_H
#define SCENE_MENUPRINCIPAL_H

#include "Scene.h"

class Scene_MenuPrincipal : Scene
{
    public:
    Scene_MenuPrincipal(Gestionnaire_Images* gi);
    virtual void run(sf::RenderWindow* app);

};

#endif // SCENE_MENUPRINCIPAL_H

