# Clash-Robale

Etudiants :
PAULY alexandre
MERDINGER léo

//-------------------------------------------------
But de l'execice : 

L'objectif de l'exercice était de coder un jeu multi-joueur en C++, incluant la possibilité d'ajouter une IA remplacant l'un des deux joueurs.
Le but etant d'allier une bonne modelisation avec un code robuste, clair, efficace et qui utilise le langage correctement.

L'affichage graphique à été entierement réalisé à l'aide de la bibliotèque SFML2. 

//-------------------------------------------------
Presentation du jeu :
Le jeu est inspiré de "Age of War" et de "Clash royal";
le but est de detruire la tour de l'adversaire à l'aide
multiples troupes et sorts. 

Toutes les secondes, chaque joueur reçois un elexir,
c'est la resource du jeu.

C'est alors à eux de déplacer leurs curseur afin de placer 
des robots ou des sorts.
Les sorts peuvent etre placés sur tout le terrain, alors 
que les troupes ne peuvent etre placées que dans les tiers 
respetifs de joueurs du terrain.

//-------------------------------------------------
Bibiliotèque utilisé pour le projet :
-SFML2 pour l'affichage graphique
-Iostream pour le codage en langage objet pour le C++
-Thread afin d'avoir deux processus en simultané (l'affichage et le jeu)
-Chrono permet de mettre en pause l'un des thread pour une durée determiné.
-Mutex permet d'ameliorer la protection des variables que les deux threads manipulent simultanément

//-------------------------------------------------
Comment compiler notre programme ? Quelle biblioteque faut il avoir ?

En premier lieu il faut préalablement installer la bibliotèque SFLM.

Une fois celle-ci installé, il suffit de pull (ou telecharger) l'integralité
de la branche main du git fournis. Si vous lisez ce README vous avez déja très 
probablement deja réalisé cette étape.

Maintenant dans votre terminal, allez dans le dossier Clash-Robale puis
effectuez les commandes suivantes : 
$make
$./clash_Robale

Le jeu devrait s'ouvrir. 

//-------------------------------------------------
liste des fichers du projet :
-Makefile              simplifie la compilation du jeu
-perso.hpp/.cpp        creation de la classe et des fonctions lié aux creature du jeu
-tour.hpp/.cpp         creation de la classe et des fonctions lié à la tour de chaque joueur
-sort.hpp/.cpp         creation de la classe et des fonctions lié aux sort du jeu
-joueur.hpp/.cpp       creation de la classe et des fonctions lié aux deux joueurs du jeu
-terrain.hpp/.cpp      creation de la classe terrain et les fonctions permettant le deroulement du jeu
-affichage.cpp         fonction permettant l'affichage graphique du jeu. 
-dossier "affichage"   dissier contenant tout les éléments graphiques du jeu



//-------------------------------------------------
Informations sur les sorts et personnages: 

L'Inferterie :
À une plus grande portée que les autres robots, mais elle à
 moins de vie et fait moins de dégat. 

Le Pekka :
Il fait mal, il est rapide et il frappe ses adversaires avec vigueur.

Le Geant : 
Le sac a points de vie par excellence, sa taille est
proportionnelle à sa lenteur. Même si ses coups font mal,
il ne frappera que la tour de d'adversaire. Il ne 
dedegnera même pas regarder les autres troupes qu'il 
croisera et continura son chemin.

Le sort de soin :
Soigne tout les robots du joueurs qui joue le sort sur une 
zone.

Le sort de poison :
Deploit une zone toxique qui attaquera tout les adversaire 
s'y trouvant, et qui ralentira également.

La boule de feu :
Appelle un meteor à tomber sur une zone afin de detruire
les tours adversaires, peu de troupe resiste à sa 
puissance.