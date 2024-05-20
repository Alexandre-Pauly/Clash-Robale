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





