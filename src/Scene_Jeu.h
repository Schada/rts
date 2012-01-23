#ifndef SCENE_JEU_H
#define SCENE_JEU_H

#include "Scene.h"


class Scene_Jeu : public Scene
{
    public:
        Scene_Jeu(Gestionnaire_Images* gi);
        virtual ~Scene_Jeu();
    private:
        Gestionnaire_Images _gi;
};

#endif // SCENE_JEU_H
