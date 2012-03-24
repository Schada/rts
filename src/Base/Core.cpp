#include "Core.h"

const std::string Core::dossierMod = DOSSIER_DONNEES + Core::RecupValeurLigne(FICHIER_DEFAUT, "[General]", "Mod") + FIN_DOSSIER;
const std::string Core::fichierMod = Core::dossierMod + FICHIER_MOD;
sf::Mutex* Core::win_mu = new sf::Mutex();

Core::Core() : _eng_game(NULL), _eng_gfx(NULL), _eng_son(NULL), _app(NULL), _event(), _eng_event(ALL, QUIT, "", NULL), _scene(NULL), _numeroScene(0)
{
    /// Creation et configuration de la fenetre de jeu
    _app = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Land of Martyrs");
    //_app->SetFramerateLimit(60); // Limite la fenêtre à 60 images par seconde
    _app->SetActive(false);


    // Creation des differents moteurs du jeu
    _eng_game = new Engine_Game(this, _app, "Game");
	_eng_gfx = new Engine_Graphics(this, _app, "Graphics");
	_eng_son = new Engine_Sound(this, _app, "Sound");


    // Permet de lier les moteurs entre eux
	_eng_game->attach_engine_graphics(_eng_gfx);
	_eng_game->attach_engine_sound(_eng_son);

	_eng_gfx->attach_engine_game(_eng_game);
	_eng_gfx->attach_engine_sound(_eng_son);

	_eng_son->attach_engine_game(_eng_game);
	_eng_son->attach_engine_graphics(_eng_gfx);


    // Permet de lancer les moteurs
	_eng_game->Launch();
	_eng_gfx->Launch();
	_eng_son->Launch();


	//Permet de synchroniser les moteurs entre eux
	_eng_game->lancer();
	_eng_gfx->lancer();
	_eng_son->lancer();

    // On lance la premiere scene du jeu
    changerScene(MENU_PRINCIPAL, true);

}

Core::~Core()
{
    std::cout << "Debut Core FIN" << std::endl;
    delete _scene;
    delete _eng_game;
    delete _eng_gfx;
    delete _eng_son;

    delete _app;
    std::cout << "Core FIN" << std::endl;
}

void Core::run()
{
    while (_app->IsOpened())
    {
        // On lock le mutex avant de recuperer les events
        Core::win_mu->Lock();
        while (_app->GetEvent(_event))
        {
            // On unlock le mutex et on traite l'event recuperer en fonction de la scene
            Core::win_mu->Unlock();

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
                case OPTIONS:
                events_Options();
                break;
                case ALL:
                events_All();
                break;
                default:
                std::cerr << "La Scene est invalide !" << std::endl;
                exit(-1);
            }

            // On lock pour recuperer l'event au prochain tour de boucle
            Core::win_mu->Lock();
        }
        // On unlock dans le cas ou il n'y avait plus d'event
        Core::win_mu->Unlock();

    }
}

void Core::changerScene(int scene, bool all)
{
    if(all)
    {
        // On demande aux moteurs de mettre leur pointeur de la scene a NULL
        _eng_event.changerEvent(ALL, CHANGE, "NULL", NULL);
        envoiMultiple();

        // On attend que les moteurs aient fini
        attendreFinScene();
    }

    if(_scene)
    {
        // On supprime la scene
        delete _scene;
        _scene = NULL;
    }
    switch(scene)
    {
        // Creer la nouvelle scene
        case MENU_PRINCIPAL:
        _scene = new MenuPrincipal(_app);
        _eng_event.changerEvent(MENU_PRINCIPAL, LOAD, "MUSIQUE", NULL);
        _eng_son->push_event(_eng_event);
        break;
        case JEU:
        _scene = new Jeu(_app);
        break;
        case CHARGEMENT:
        _scene = new Chargement(_app);
        break;
        case OPTIONS:
        _scene = new Options(_app);
        break;
        default:
        std::cerr << "La scene n'existe pas " << std::endl;
        exit(-1);
    }

    _numeroScene = scene;

    if(all)
    {
        // On demande aux moteurs de recuperer la nouvelle scene
        _eng_event.changerEvent(ALL, CHANGE, "SCENE", NULL);
        envoiMultiple();

        // On attend que la scene soit initialiser avant de recuperer les evenements
        while(_scene->isInit() == false);
    }
}
void Core::attendreFinScene()
{
    while(!_eng_game->sceneFinie());
    while(!_eng_gfx->sceneFinie());
    while(!_eng_son->sceneFinie());
}

Scene* Core::get_Scene()
{
    return _scene;
}

int Core::get_numeroScene()
{
    return _numeroScene;
}

void Core::envoiMultiple()
{
    std::cerr << "Message envoye !" << std::endl;
    _eng_gfx->push_event(_eng_event);
    _eng_game->push_event(_eng_event);
    _eng_son->push_event(_eng_event);
}

std::string Core::RecupValeurLigne(std::string lienFichier, std::string balise, std::string nomLigne)
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

std::string Core::RecupValeurNumeroLigne(std::string lienFichier, std::string balise, int numeroLigne)
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

bool Core::VerifExistanceNom(std::string lienFichier, std::string nomLigne, std::string balise)
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

bool Core::VerifExistanceVal(std::string lienFichier, std::string nomLigne, std::string val, std::string balise)
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

void Core::events_MenuPrincipal()
{
    sf::Vector2f PlaySize = (_scene->get_sprite("Play"))->GetSize();
    sf::Vector2f PlayPos = (_scene->get_sprite("Play"))->GetPosition();
    sf::Vector2f QuitSize = (_scene->get_sprite("Quit"))->GetSize();
    sf::Vector2f QuitPos = (_scene->get_sprite("Quit"))->GetPosition();

    int MouseX = _event.MouseButton.X;
    int MouseY = _event.MouseButton.Y;

    if (_event.Type == sf::Event::Closed)
    {
        _eng_event.changerEvent(ALL, QUIT, "QUIT", NULL);
        envoiMultiple();

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
    if(_event.Type == sf::Event::MouseButtonPressed && _event.MouseButton.Button == sf::Mouse::Left)
    {
        if(MouseX > PlayPos.x && MouseX < PlayPos.x + PlaySize.x && MouseY > PlayPos.y && MouseY < PlayPos.y + PlaySize.y )
        {
            _eng_event.changerEvent(MENU_PRINCIPAL, CLICK, "PLAY", &_event);
            envoiMultiple();

            changerScene(JEU, true);

        }
        if (MouseX > QuitPos.x && MouseX < QuitPos.x + QuitSize.x && MouseY > QuitPos.y && MouseY < QuitPos.x +QuitSize.y)
        {
            _eng_event.changerEvent(MENU_PRINCIPAL, CLICK, "QUIT", &_event);
            envoiMultiple();

            _eng_game->Wait();
            _eng_gfx->Wait();
            _eng_son->Wait();
            _numeroScene = ALL;
        }
    }
}

void Core::events_Jeu()
{
    if (_event.Type == sf::Event::Closed)
    {
        _eng_event.changerEvent(ALL, QUIT, "", NULL);
        envoiMultiple();

        _eng_game->Wait();
        _eng_gfx->Wait();
        _eng_son->Wait();
        _numeroScene = ALL;
    }
}

void Core::events_Chargement()
{
    if (_event.Type == sf::Event::Closed)
    {
        _eng_event.changerEvent(ALL, QUIT, "", NULL);
        envoiMultiple();

        _eng_game->Wait();
        _eng_gfx->Wait();
        _eng_son->Wait();
        _numeroScene = ALL;
    }
}

void Core::events_Options()
{
    if (_event.Type == sf::Event::Closed)
    {
        _eng_event.changerEvent(ALL, QUIT, "", NULL);
        envoiMultiple();

        _eng_game->Wait();
        _eng_gfx->Wait();
        _eng_son->Wait();
        _numeroScene = ALL;
    }
}

void Core::events_All()
{
    if (_event.Type == sf::Event::Closed)
    {
        _eng_event.changerEvent(ALL, QUIT, "", NULL);
        envoiMultiple();

        _eng_game->Wait();
        _eng_gfx->Wait();
        _eng_son->Wait();
        _numeroScene = ALL;
    }
}
