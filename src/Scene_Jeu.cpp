#include "Scene_Jeu.h"

Scene_Jeu::Scene_Jeu(Gestionnaire_Images* gi)
{
    _gi = gi;
}

Scene_Jeu::~Scene_Jeu()
{
    _gi = NULL;
}
