#include "perso.hpp"
#include "tour.hpp"
#include "joueur.hpp"
#include <iostream>

//************* Constructeurs **************

Geant::Geant(int joueur){
    _pv = 200; 
    _pv_max = 200;
    _degat = -4;
    _vitesse = 6;
    _joueur = joueur;
    _cout =5;
    _range = NB_CASE/30;
    _nom='G';
}

Geant::Geant(const Joueur &joueur){
    _pv = 200; 
    _pv_max = 200;
    _degat = -4;
    _vitesse = 6;
    _joueur = joueur.get_nb_joueur();
    _cout =5;
    _range = NB_CASE/30;
    _nom='G';

}


Pekka::Pekka(int joueur){
    _pv = 100;
    _pv_max = 100;
    _degat = -6;
    _vitesse = 10;
    _joueur = joueur;
    _cout = 4;
    _range = NB_CASE/30;
    _nom='P';
}
Pekka::Pekka(const Joueur &joueur){
    _pv = 100;
    _pv_max = 100;
    _degat = -6;
    _vitesse = 10;
    _joueur = joueur.get_nb_joueur();
    _cout = 4;
    _range = NB_CASE/30;
    _nom='P';
}



Infentrie::Infentrie(int joueur){
    _pv = 80;
    _pv_max = 80;
    _degat = -4;
    _vitesse = 8;
    _joueur = joueur;
    _cout = 4;
    _range = NB_CASE/15;
    _nom='I';
}

Infentrie::Infentrie(const Joueur &joueur){
    _pv = 80;
    _pv_max = 80;
    _degat = -4;
    _vitesse = 8;
    _joueur = joueur.get_nb_joueur();
    _cout = 4;
    _range = NB_CASE/15;
    _nom='I';
}

// attaque d'un personnage sur un autre
void Perso::attaquer(Perso& perso){
    perso.effet_pv(_degat);
}

// attaque d'un personnage sur une tour
void Perso::attaquer(Tour& tour){
    tour.effet_pv(_degat);
}


