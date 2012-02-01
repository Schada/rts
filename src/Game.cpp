#include "Game.h"

Game::Game()
{
    _app = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Land of Martyrs");
    _app->SetFramerateLimit(60); // Limite la fenêtre à 60 images par seconde
    _eng_game = new Engine_Game(this, _app, "Game");
	_eng_gfx = new Engine_Graphics(this, _app, "Graphics");
	_eng_son = new Engine_Sound(this, _app, "Sound");

	_eng_game->attach_engine_graphics(_eng_gfx);
	_eng_game->attach_engine_sound(_eng_son);

	_eng_gfx->attach_engine_game(_eng_game);
	_eng_gfx->attach_engine_sound(_eng_son);

	_eng_son->attach_engine_game(_eng_game);
	_eng_son->attach_engine_graphics(_eng_gfx);

	_eng_game->Launch();
	_eng_gfx->Launch();
	_eng_son->Launch();

	//Permet de synchroniser les moteurs entre eux

	_eng_game->lancer();
	_eng_gfx->lancer();
	_eng_son->lancer();
}

Game::~Game()
{
    delete _eng_game;
    delete _eng_gfx;
    delete _eng_son;
    delete _app;
}

void Game::run()
{
    _app->SetActive(false);
    while (_app->IsOpened())
    {
        sf::Event event;
        int xPlay = (*_app).GetWidth()/2-50;
        int yPlay = (*_app).GetHeight()/2-50;
        int xQuit = (*_app).GetWidth()/2-50;
        int yQuit = (*_app).GetHeight()/2-50+150;
        int MouseX = event.MouseMove.X;
        int MouseY = event.MouseMove.Y;
        while (_app->GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
            {
                Engine_Event e(MENU_PRINCIPAL, CLICK, "QUIT", "LEFT");
                _eng_gfx->push_event(e);
                _eng_game->push_event(e);
                _eng_son->push_event(e);
                _eng_game->Wait();
                _eng_gfx->Wait();
                _eng_son->Wait();
            }
            if (event.Type == sf::Event::MouseMoved)
            {
                if(MouseX > xPlay && MouseX < (xPlay + 150) && MouseY > yPlay && MouseY < (yPlay + 60) )
                {
                    Engine_Event e(MENU_PRINCIPAL, MOUSE, "PLAY", "IN");
                    _eng_gfx->push_event(e);
                }else
                    {
                        Engine_Event e(MENU_PRINCIPAL, MOUSE, "PLAY", "OUT");
                        _eng_gfx->push_event(e);
                    }
                if(MouseX > xQuit && MouseX < (xQuit + 150) && MouseY > yQuit && MouseY < (yQuit+ 60) )
                {
                    Engine_Event e(MENU_PRINCIPAL, MOUSE, "QUIT", "IN");
                    _eng_gfx->push_event(e);
                }else
                    {
                        Engine_Event e(MENU_PRINCIPAL, MOUSE, "QUIT", "OUT");
                        _eng_gfx->push_event(e);
                    }
            }
            if(event.Type == sf::Event::MouseButtonPressed && event.MouseButton.Button == sf::Mouse::Left)
            {
                if(MouseX > xPlay && MouseX < (xPlay + 150) && MouseY > yPlay && MouseY < (yPlay + 60) )
                {
                    Engine_Event e(MENU_PRINCIPAL, CLICK, "PLAY", "LEFT");
                    _eng_son->push_event(e);
                    _eng_gfx->push_event(e);
                }
                if (MouseX > xQuit && MouseX < (xQuit + 150) && MouseY > yQuit && MouseY < (yQuit+ 60) )
                {
                    Engine_Event e(MENU_PRINCIPAL, CLICK, "QUIT", "LEFT");
                    _eng_gfx->push_event(e);
                    _eng_game->push_event(e);
                    _eng_son->push_event(e);
                    _eng_game->Wait();
                    _eng_gfx->Wait();
                    _eng_son->Wait();
                }
            }
        }
    }
}

std::string Game::RecupValeurLigne(std::string lienFichier, std::string balise, std::string nomLigne)
{
    std::ifstream fichier(lienFichier.c_str(), std::ios::in);
    if(fichier)
    {
        std::string ligne;

         // Parcourt le fichier jusqu'à trouver la balise ou la fin du fichier
        do
        {
        }while((getline(fichier, ligne)) && (ligne != balise));

        if(ligne == balise) // Si la balise a été trouver
        {
            std::string nom, vide, valeur;

             //On parcourt les lignes de la balise jusqu'à la balise [Fin]

            do
            {
                fichier >> nom;
                if(nom != "[Fin]")// Si la ligne actuelle n'est pas la balise [Fin]
                {

                    fichier >> vide >> valeur; // On recupere le egale et la valeur de la ligne
                    if(nom == nomLigne) // SI la ligne porte le nom recherché on renvoit la valeur de cette ligne
                    {
                        fichier.close();
                        return valeur;
                    }

                }


            }while((!fichier.eof()) && (nom != "[Fin]"));
            if(nom != "[Fin]") // Si la balise [Fin] n'a pas été trouver
            {
                std::cerr << "Balise [Fin] de " + balise + " introuvable" << std::endl;
            }
            else
            {
                std::cerr << "Ligne introuvable" << std::endl;
            }

        }
        else // Si la balise consernée n'a pas été trouver
        {
            std::cerr << "Balise " + balise + " introuvable" << std::endl;
        }
        fichier.close();
    }
    else
    {
        std::cerr << "Le fichier " << lienFichier << " est introuvable." << std::endl;
    }
    return "";
}

bool Game::VerifExistanceNom(std::string lienFichier, std::string nomLigne, std::string balise)
{
    std::ifstream fichier(lienFichier.c_str(), std::ios::in);
    if(fichier)
    {
        std::string ligne;

         // Parcourt le fichier jusqu'à trouver la balise ou la fin du fichier
        do
        {
        }while((getline(fichier, ligne)) && (ligne != balise));

        if(ligne == balise) // Si la balise a été trouver
        {
            std::string nom;

             //On parcourt les lignes de la balise jusqu'à la balise [Fin]

            do
            {
                fichier >> nom;
                if(nomLigne == nom)// Si la ligne actuelle n'est pas la balise [Fin]
                {
                    fichier.close();
                    return true;
                }

            }while((!fichier.eof()) && (nom != "[Fin]"));
        }
        fichier.close();
    }
    else
    {
        std::cerr << "Le fichier " << lienFichier << " est introuvable." << std::endl;
    }
    return false;
}

bool Game::VerifExistanceVal(std::string lienFichier, std::string nomLigne, std::string val, std::string balise)
{
    std::ifstream fichier(lienFichier.c_str(), std::ios::in);
    if(fichier)
    {
        std::string ligne;

         // Parcourt le fichier jusqu'à trouver la balise ou la fin du fichier
        do
        {
        }while((getline(fichier, ligne)) && (ligne != balise));

        if(ligne == balise) // Si la balise a été trouver
        {
            std::string nom, vide, valeur;

             //On parcourt les lignes de la balise jusqu'à la balise [Fin]

            do
            {
                fichier >> nom;
                if(nom != "[Fin]")// Si la ligne actuelle n'est pas la balise [Fin]
                {

                    fichier >> vide >> valeur; // On recupere le egale et la valeur de la ligne
                    if(nom == nomLigne) // SI la ligne porte le nom recherché on renvoit la valeur de cette ligne
                    {
                        fichier.close();
                        if(valeur == val)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }while((!fichier.eof()) && (nom != "[Fin]"));
            if(nom != "[Fin]") // Si la balise [Fin] n'a pas été trouver
            {
                std::cerr << "Balise [Fin] de " + balise + " introuvable" << std::endl;
            }
            else
            {
                std::cerr << "Ligne introuvable" << std::endl;
            }

        }
        else // Si la balise consernée n'a pas été trouver
        {
            std::cerr << "Balise " + balise + " introuvable" << std::endl;
        }
        fichier.close();
    }
    else
    {
        std::cerr << "Le fichier " << lienFichier << " est introuvable." << std::endl;
    }
    return false;
}

