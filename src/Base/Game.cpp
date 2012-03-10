#include "Game.h"

const std::string Game::dossierMod = DOSSIER_DONNEES + Game::RecupValeurLigne(FICHIER_DEFAUT, "[General]", "Mod") + FIN_DOSSIER;
const std::string Game::fichierMod = Game::dossierMod + FICHIER_MOD;

Game::Game() : _eng_game(NULL), _eng_gfx(NULL), _eng_son(NULL), _app(NULL), _scene(NULL), _numeroScene(0)
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

    changerScene(JEU, true);

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
    std::cout << "Debut FIN" << std::endl;
    delete _scene;
    delete _eng_game;
    delete _eng_gfx;
    delete _eng_son;

    delete _app;
    std::cout << "OK" << std::endl;
}

void Game::run()
{
    while (_app->IsOpened())
    {
        switch(_numeroScene)
        {
            case MENU_PRINCIPAL:
            events_MenuPrincipal();
            break;
            case CHARGEMENT:
            events_Chargement();
            break;
            case JEU:
            events_Jeu();
            break;
            case ALL:
            events_All();
            break;
            default:
            std::cerr << "La Scene est invalide !" << std::endl;
            exit(-1);
        }

    }
}

void Game::changerScene(int scene, bool all)
{
    if(all)
    {
        Engine_Event e(ALL, CHANGE, "NULL", NULL);
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
        case CHARGEMENT:
        _scene = new Scene_Chargement(_app);
        break;
        default:
        std::cerr << "La scene n'existe pas " << std::endl;
        exit(-1);
    }

    _numeroScene = scene;

    if(all)
    {
        Engine_Event e(ALL, CHANGE, "SCENE", NULL);
        envoiMultiple(e);
    }
}

Scene* Game::get_Scene()
{
    return _scene;
}

int Game::get_numeroScene()
{
    return _numeroScene;
}

void Game::envoiMultiple(Engine_Event& e)
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

std::string Game::RecupValeurNumeroLigne(std::string lienFichier, std::string balise, int numeroLigne)
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
            int i = 0;

             //On parcourt les lignes de la balise jusqu'à la balise [Fin]

            do
            {
                i++;
                getline(fichier, nom);

                if(i == numeroLigne)// Si la ligne actuelle n'est pas la balise [Fin]
                {
                    fichier.close();
                    return nom;
                }

            }while((!fichier.eof()) && (nom != "[Fin]"));
            if(nom != "[Fin]") // Si la balise [Fin] n'a pas été trouver
            {
                std::cerr << "Balise [Fin] de " + balise + " introuvable" << std::endl;
            }
            else
            {
                std::cerr << "Ligne introuvable" << std::endl;
                return nom;
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

void Game::events_MenuPrincipal()
{
    while(!(_scene->isInit()));

    sf::Event event;
    sf::Vector2f PlaySize = (_scene->get_sprite("Play"))->GetSize();
    sf::Vector2f PlayPos = (_scene->get_sprite("Play"))->GetPosition();
    sf::Vector2f QuitSize = (_scene->get_sprite("Quit"))->GetSize();
    sf::Vector2f QuitPos = (_scene->get_sprite("Quit"))->GetPosition();

    int MouseX = event.MouseMove.X;
    int MouseY = event.MouseMove.Y;

    Engine_Event e(MENU_PRINCIPAL, LOAD, "MUSIQUE", NULL);
    _eng_son->push_event(e);




    while(_numeroScene == MENU_PRINCIPAL)
    {
        MouseX = event.MouseMove.X;
        MouseY = event.MouseMove.Y;
        while (_app->GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
            {
                e.changerEvent(ALL, QUIT, "QUIT", NULL);
                envoiMultiple(e);

                _eng_game->Wait();
                _eng_gfx->Wait();
                _eng_son->Wait();
                _numeroScene = ALL;
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
                    e.changerEvent(MENU_PRINCIPAL, CLICK, "PLAY", &event);
                    envoiMultiple(e);
                }
                if (MouseX > QuitPos.x && MouseX < QuitPos.x + QuitSize.x && MouseY > QuitPos.y && MouseY < QuitPos.x +QuitSize.y)
                {
                    e.changerEvent(MENU_PRINCIPAL, CLICK, "QUIT", &event);
                    envoiMultiple(e);

                    _eng_game->Wait();
                    _eng_gfx->Wait();
                    _eng_son->Wait();
                    _numeroScene = ALL;
                }
            }
        }
    }
}
void Game::events_Jeu()
{
    while(!(_scene->isInit()));

    Engine_Event e(ALL, QUIT, "QUIT", NULL);
    sf::Event event;

    while(_numeroScene == JEU)
    {
        while (_app->GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
            {

                envoiMultiple(e);

                _eng_game->Wait();
                _eng_gfx->Wait();
                _eng_son->Wait();
                _numeroScene = ALL;
            }
        }
    }
}

void Game::events_Chargement()
{
    while(!(_scene->isInit()));

    Engine_Event e(ALL, QUIT, "", NULL);
    sf::Event event;

    while(_numeroScene == CHARGEMENT)
    {
        while (_app->GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
            {

                envoiMultiple(e);

                _eng_game->Wait();
                _eng_gfx->Wait();
                _eng_son->Wait();
                _numeroScene = ALL;
            }
        }
    }
}


void Game::events_All()
{
    while(!(_scene->isInit()));

    Engine_Event e(ALL, QUIT, "", NULL);
    sf::Event event;

    while(_numeroScene == ALL)
    {
        while (_app->GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
            {

                envoiMultiple(e);

                _eng_game->Wait();
                _eng_gfx->Wait();
                _eng_son->Wait();
                _numeroScene = ALL;
            }
        }
    }
}

