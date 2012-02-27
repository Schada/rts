#include "Game.h"

Game::Game() : _eng_game(NULL), _eng_gfx(NULL), _eng_son(NULL), _app(NULL), _scene(NULL)
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

    changerScene(MENU_PRINCIPAL, true);

    _app->SetActive(false);

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
    delete _scene;
    delete _app;
}

void Game::run()
{

    while(!(_scene->isInit()));

    sf::Event event;
    sf::Vector2f PlaySize = (_scene->get_sprite("Play"))->GetSize();
    sf::Vector2f PlayPos = (_scene->get_sprite("Play"))->GetPosition();
    sf::Vector2f QuitSize = (_scene->get_sprite("Quit"))->GetSize();
    sf::Vector2f QuitPos = (_scene->get_sprite("Quit"))->GetPosition();

    int MouseX = event.MouseMove.X;
    int MouseY = event.MouseMove.Y;

    Engine_Event e(MENU_PRINCIPAL, LOAD, "MUSIQUE", "test");
    _eng_son->push_event(e);


    while (_app->IsOpened())
    {
        MouseX = event.MouseMove.X;
        MouseY = event.MouseMove.Y;
        while (_app->GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
            {
                e.changerEvent(MENU_PRINCIPAL, CLICK, "QUIT", "LEFT");
                envoiMultiple(e);

                _eng_game->Wait();
                _eng_gfx->Wait();
                _eng_son->Wait();
            }
            /*if (event.Type == sf::Event::MouseMoved)
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
            }*/
            if(event.Type == sf::Event::MouseButtonPressed && event.MouseButton.Button == sf::Mouse::Left)
            {
                if(MouseX > PlayPos.x && MouseX < PlayPos.x + PlaySize.x && MouseY > PlayPos.y && MouseY < PlayPos.y + PlaySize.y )
                {
                    e.changerEvent(MENU_PRINCIPAL, CLICK, "PLAY", "LEFT");
                    envoiMultiple(e);
                }
                if (MouseX > QuitPos.x && MouseX < QuitPos.x + QuitSize.x && MouseY > QuitPos.y && MouseY < QuitPos.x +QuitSize.y)
                {
                    e.changerEvent(MENU_PRINCIPAL, CLICK, "QUIT", "LEFT");
                    envoiMultiple(e);

                    _eng_game->Wait();
                    _eng_gfx->Wait();
                    _eng_son->Wait();
                }
            }
        }
    }
}

void Game::changerScene(int scene, bool all)
{
    if(all)
    {
        Engine_Event e(ALL, CHANGE, "SCENE", "NULL");
        envoiMultiple(e);
    }


    if(_scene)
    {
        delete _scene;
        _scene = NULL;
    }
    switch(scene)
    {
        case MENU_PRINCIPAL:

        _scene = new Scene_MenuPrincipal(_app);
        break;
        case JEU:
        _scene = new Scene_Jeu(_app);
        break;
        default:
        std::cerr << "La scene n'existe pas " << std::endl;
        exit(-1);
    }

    if(all)
    {
        Engine_Event e(ALL, CHANGE, "SCENE", "");
        envoiMultiple(e);
    }
}

Scene* Game::get_Scene()
{
    return _scene;
}

void Game::envoiMultiple(Engine_Event e)
{
    _eng_gfx->push_event(e);
    _eng_game->push_event(e);
    _eng_son->push_event(e);
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

