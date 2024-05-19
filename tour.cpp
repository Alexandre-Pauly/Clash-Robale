#include  "tour.hpp"
#include "perso.hpp"
#include "joueur.hpp"

Tour::Tour(){
    _range = NB_CASE/15;
    _pv = 600;
    _degat = -4;
    _attaque = 0;
}


void Tour::attaquer(Perso& perso){
    perso.effet_pv(_degat);
}