La krakoukass-Team aime le caca !!!

Bibliotheques utilisées :
 * Sfml
 * Qt

Explications sur les Threads :
 * Thread Principal : Initialise et demarre les autres Threads puis regarde les entrées (clavier et souris) et les stock dans un buffer
 * Thread Engine_Game : Manipule les différents éléments du jeu (pathfinding ...)
 * Thread Engine_Graphics : Gere l'affichage du jeu (Ecrans)
 * Thread Engine_Sound : Gere le son dans le jeu
 
Les messages des moteurs sont composés de :
	Une Scene, int
	Un Type, int
	Un Nom, std::string
	Un Parametre, std::string
	
Scene, valeur possible : MENU_PRINCIPAL, CHARGEMENT, JEU, ALL
Type, valeur possible : MOUSE, CLICK, KEY, LOAD, CHANGE

Le type MOUSE est utilisé lorsque la souris vient sur un élément ou le quitte.
Il a pour parametre :
	IN 
	OUT
	
Le type CLICK est utilisé lorsque un click de souris est utilisé.
Il a pour parametre :
	LEFT
	RIGHT
	
Le type KEY est utilisé lors d'un appuie sur une touche du clavier.
Il a pour parametre la touche pressée (avec casse).

Le type LOAD est utilisé lors d'un chargement de fichier.
Sans paramètre.

Le type CHANGE est utilisé lors d'un changement de Scene.
On utilise CHANGE avec ALL car le changement de scene n'a ni besoin de la source ni de la destination (C'est la classe Game qui s'occupe de l'allocation de la nouvelle Scene)
Il a pour paramêtre :
 	NULL : Met à NULL la scene Active des moteurs pour procéder au changement
	Pas de Valeur : Chaque moteur va récupérer la scene active à la classe Game
 
 
 
 
 
 
 