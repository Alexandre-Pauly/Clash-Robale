# Clash-Robale

Etudiants :
PAULY alexandre
MERDINGER léo

//-------------------------------------------------
But de l'execice : 

L'objectif de l'exercice était de coder un jeu multi-joueur en C++, incluant la possibilité d'ajouter une IA remplacant l'un des deux joueurs.
Le but étant d'allier une bonne modélisation avec un code robuste, clair, efficace et qui utilise le langage correctement.

L'affichage graphique à été entierement réalisé à l'aide de la bibliotèque SFML2. 

//-------------------------------------------------
Presentation du jeu :
Le jeu est inspiré de "Age of War" et de "Clash Royale";
le but est de detruire la tour de l'adversaire à l'aide de
multiples troupes et sorts. 

Toutes les secondes, chaque joueur reçoit un élixir,
c'est la ressource du jeu.

C'est alors à eux de déplacer leur curseur afin de placer 
des robots ou des sorts.
Les sorts peuvent être placés sur tout le terrain, alors 
que les troupes ne peuvent être placées que dans le tiers 
respectif de chaque joueur.

//-------------------------------------------------
Bibliothèque utilisée pour le projet :
-SFML2 pour l'affichage graphique
-Iostream afin d'améliorer l'utilisation du terminal (ex : std::cout)
-Thread afin d'avoir deux processus en simultané (l'affichage et le jeu + un IA plus tard ?)
-Chrono permet de mettre en pause l'un des thread pour une durée determiné.
-Mutex permet d'ameliorer la protection des données que les deux threads manipulent

//-------------------------------------------------
Comment compiler notre programme ? Quelle bibliothèque faut-il avoir ?

En premier lieu il faut préalablement installer la bibliothèque SFLM.

Une fois celle-ci installé, il suffit de pull (ou télécharger) l'integralité
de la branche main du git fournis. Si vous lisez ce README vous avez déja très 
probablement déjà réalisé cette étape.

Maintenant dans votre terminal, allez dans le dossier Clash-Robale puis
effectuez les commandes suivantes : 
$ make
$ ./clash_Robale

Le jeu devrait s'ouvrir. 

//-------------------------------------------------
liste des fichers du projet :
-Makefile              simplifie la compilation du jeu
-perso.hpp/.cpp        creation de la classe et des fonctions liées aux creatures du jeu
-tour.hpp/.cpp         creation de la classe et des fonctions liées à la tour de chaque joueur
-sort.hpp/.cpp         creation de la classe et des fonctions liées aux sort du jeu
-joueur.hpp/.cpp       creation de la classe et des fonctions liées aux deux joueurs 
-terrain.hpp/.cpp      creation de la classe terrain et les fonctions permettant le déroulement du jeu
-affichage.cpp         fonction permettant l'affichage graphique du jeu. 
-dossier "affichage"   dossier contenant tous les éléments graphiques du jeu
-test.cpp              fichier de test à compiler avec "make test"



//-------------------------------------------------
Informations sur les sorts et personnages: 

L'Infanterie :
A une plus grande portée que les autres robots, mais elle a
 moins de points de vie et fait moins de dégats. 

Le Pekka :
Il fait mal, il est rapide et il frappe ses adversaires avec vigueur.

Le Geant : 
Le sac a points de vie par excellence, sa taille est
proportionnelle à sa lenteur. Même si ses coups font mal,
il ne frappera que la tour de l'adversaire. Il ne 
daignera même pas regarder les autres troupes qu'il 
croisera et continura son chemin.

Le sort de soin :
Soigne tous les robots du joueurs qui joue le sort sur une 
zone.

Le sort de poison :
Deploit une zone toxique qui attaquera tous les adversaires 
s'y trouvant, et qui les ralentira également.

La boule de feu :
Appelle une météorite sur une zone afin de détruire troupes et
tours adverses, peu de troupes resistent à sa 
puissance.
