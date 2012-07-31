#include "Scene.h"

#include "../Base/Core.h"

Scene::Scene(sf::RenderWindow* app, std::string nom, std::string fond)
{
    _app = app;
    _gi = NULL;
    _gm = NULL;
    _gs = NULL;
    _gfxInit = false;
    _sonInit = false;
    _jeuInit = false;

    _nom = nom;
    _nomFond = fond;
    _fond = NULL;

    initInterface();
}

Scene::~Scene()
{
    _app = NULL;
    _gi = NULL;
    _gm = NULL;
    _gs = NULL;

    for(unsigned int i = 0 ; i < _elements.size() ; i++)
    {
        if(_elements.at(i) != NULL)
        {
            delete _elements.at(i);
        }
    }

    if(_fond != NULL)
    {
        delete _fond;    }
}

void Scene::set_gi(Gestionnaire_Images* gi)
{
    _gi = gi;
}

void Scene::set_gm(Gestionnaire_Musiques* gm)
{
    _gm = gm;
}

void Scene::set_gs(Gestionnaire_Sons* gs)
{
    _gs = gs;
}

bool Scene::isInit()
{
    if(_gfxInit)
    {
        if(_sonInit)
        {
            if(_jeuInit)
            {
                return true;
            }
        }
    }

    return false;
}

void Scene::initGfx()
{
    std::string nomImage;
    std::vector < std::string > tab;
    sf::Image* image = _gi->get_contenu(_nomFond);
    for(unsigned int i = 0 ; i < _elements.size() ; i++)
    {
        tab.clear();
        nomImage = Core::RecupValeurLigne(_fichier, "[Sprites]", (_elements.at(i))->getNom());
        if(nomImage != "")
        {
            Core::decouperTexte(nomImage, &tab);
            std::cout << "TAILLE de " << nomImage << " : " << tab.size() << std::endl;
            (_elements.at(i))->setImage(_gi->get_contenu(tab[0]));
            (_elements.at(i))->setPositionInSprite(atoi(tab[1].c_str()),atoi(tab[2].c_str()));
        }
    }

    if(image != NULL)
    {
        _fond = new sf::Sprite();
        _fond->SetImage(*image);
        _fond->Resize(800,600);
    }


    _gfxInit = true;

}

void Scene::initSon()
{
    _sonInit = true;
}

void Scene::initJeu()
{
    _jeuInit = true;
}

float Scene::time()
{
    return floor(_clock.GetElapsedTime());
}

void Scene::initInterface()
{
    int i = 1;
    _fichier = Core::dossierScene + _nom + ".scene";
    std::string ligne, type;
    std::vector < std::string > tab;

    IElement* element;

    ligne = Core::RecupValeurNumeroLigne(_fichier, "[Elements]", i);

    do
    {
        tab.clear();
        Core::decouperTexte(ligne, &tab, 6);

        if(!existeElement(tab[1]))
        {
            type = tab[0];

            if(type == "TEXTE")
            {
                element = new ITexte(_app, tab[1]);

                element->setPositionSprite(atof(tab[2].c_str()), atof(tab[3].c_str()));
                //element->setSize(tab->at(4), tab->at(5));
                element->setTexte(tab[6]);

                _elements.push_back(element);

                std::cout << "Creation de Texte" << std::endl;
            }
            else if(type == "BOUTONPUSH")
            {
                std::cout << "Creation de Bouton" << std::endl;
            }
            else if(type == "ZONETEXTE")
            {
                std::cout << "Creation de ZoneTexte" << std::endl;
            }
            else
            {
                std::cout << "Type inconnu, la ligne | " << ligne << " | est ignoree." << std::endl;
            }
        }
        else
        {
            std::cout << "L element " << tab[1] << " existe deja." << std::endl;
        }

        i++;
        ligne = Core::RecupValeurNumeroLigne(_fichier, "[Elements]", i);
    }while(ligne != "[FIN]");
}

void Scene::afficher()
{
    if(_fond != NULL)
    {
        _app->Draw(*_fond);
    }

    for(unsigned int i = 0 ; i < _elements.size() ; i++)
    {
        (_elements.at(i))->afficher();
    }
}

bool Scene::existeElement(std::string nom)
{
    for(unsigned int i = 0 ; i < _elements.size() ; i++)
    {
        if(_elements[i]->getNom() == nom)
        {
            return true;
        }
    }

    return false;
}
