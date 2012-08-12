#ifndef CONSTANTES_H
#define CONSTANTES_H

#define WIN
#ifdef WIN
#define FIN_DOSSIER "\\"
#endif
#ifdef LINUX
#define FIN_DOSSIER "/"
#include <X11/Xlib.h>
#endif

#define DOSSIER_DONNEES "Data"FIN_DOSSIER
#define FICHIER_DEFAUT "rts.dat"
#define FICHIER_MOD "Mod.dat"
#define IMG_DOSSIER "img"FIN_DOSSIER

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

struct Struct_File
{
    std::string nom;
    std::ifstream fichier;

};

enum Event_Scene {MENU_PRINCIPAL, CHARGEMENT, JEU, OPTIONS, CONSOLE, ALL};
enum Event_Type {MOUSE, CLICK, KEY, LOAD, MUSIQUE, CHANGE, QUIT};

#endif // CONSTANTES_H
