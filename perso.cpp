#include "perso.hpp"
#include "tour.hpp"
#include "joueur.hpp"
#include <iostream>

Geant::Geant(int joueur){
    _pv = 20; 
    _pv_max = 20;
    _degat = -4;
    _vitesse = 2;
    _joueur = joueur;
    _cout =5;
    _range = 1;
    _nom='G';
}

Geant::Geant(const Joueur &joueur){
    _pv = 20; 
    _pv_max = 20;
    _degat = -4;
    _vitesse = 2;
    _joueur = joueur.get_nb_joueur();
    _cout =5;
    _range = 1;
    _nom='G';

}


Pekka::Pekka(int joueur){
    _pv = 10;
    _pv_max = 10;
    _degat = -6;
    _vitesse = 4;
    _joueur = joueur;
    _cout = 4;
    _range = 1;
    _nom='P';
}
Pekka::Pekka(const Joueur &joueur){
    _pv = 10;
    _pv_max = 10;
    _degat = -6;
    _vitesse = 4;
    _joueur = joueur.get_nb_joueur();
    _cout = 4;
    _range = 1;
    _nom='P';
}



Infentrie::Infentrie(int joueur){
    _pv = 8;
    _pv_max = 8;
    _degat = -4;
    _vitesse = 3;
    _joueur = joueur;
    _cout = 4;
    _range = 4;
    _nom='I';
}

Infentrie::Infentrie(const Joueur &joueur){
    _pv = 8;
    _pv_max = 8;
    _degat = -4;
    _vitesse = 3;
    _joueur = joueur.get_nb_joueur();
    _cout = 4;
    _range = 4;
    _nom='I';
}


void Perso::attaquer(Perso& perso){
    perso.effet_pv(_degat);
}


void Perso::attaquer(Tour& tour){
    tour.effet_pv(_degat);
}


