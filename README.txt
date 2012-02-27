La krakoukass-Team aime le caca !!!

Bibliotheques utilis�es :
 * Sfml
 * Qt

Explications sur les Threads :
 * Thread Principal : Initialise et demarre les autres Threads puis regarde les entr�es (clavier et souris) et les stock dans un buffer
 * Thread Engine_Game : Manipule les diff�rents �l�ments du jeu (pathfinding ...)
 * Thread Engine_Graphics : Gere l'affichage du jeu (Ecrans)
 * Thread Engine_Sound : Gere le son dans le jeu
 
Les messages des moteurs sont compos�s de :
	Une Scene, int
	Un Type, int
	Un Nom, std::string
	Un Parametre, std::string
	
Scene, valeur possible : MENU_PRINCIPAL, CHARGEMENT, JEU, ALL
Type, valeur possible : MOUSE, CLICK, KEY, LOAD, CHANGE

Le type MOUSE est utilis� lorsque la souris vient sur un �l�ment ou le quitte.
Il a pour parametre :
	IN 
	OUT
	
Le type CLICK est utilis� lorsque un click de souris est utilis�.
Il a pour parametre :
	LEFT
	RIGHT
	
Le type KEY est utilis� lors d'un appuie sur une touche du clavier.
Il a pour parametre la touche press�e (avec casse).

Le type LOAD est utilis� lors d'un chargement de fichier.
Sans param�tre.

Le type CHANGE est utilis� lors d'un changement de Scene.
On utilise CHANGE avec ALL car le changement de scene n'a ni besoin de la source ni de la destination (C'est la classe Game qui s'occupe de l'allocation de la nouvelle Scene)
Il a pour param�tre :
 	NULL : Met � NULL la scene Active des moteurs pour proc�der au changement
	Pas de Valeur : Chaque moteur va r�cup�rer la scene active � la classe Game
 
 
 
 
 
 
 