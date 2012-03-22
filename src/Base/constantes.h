#ifndef CONSTANTES_H
#define CONSTANTES_H

#define DOSSIER_DONNEES "Data/"
#define FICHIER_DEFAUT "rts.dat"
#define FICHIER_MOD "Mod.dat"
#define FIN_DOSSIER "/"
#define IMG_DOSSIER "img/"

#include <SFML/Graphics.hpp>


enum Event_Scene {MENU_PRINCIPAL, CHARGEMENT, JEU, ALL};
enum Event_Type {MOUSE, CLICK, KEY, LOAD, MUSIQUE, CHANGE, QUIT};

#endif // CONSTANTES_H
