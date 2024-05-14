#include  "tour.hpp"
#include "perso.hpp"
#include "joueur.hpp"

Tour::Tour(){
    _range = 6;
    _pv = 125;
    _degat = -4;
}


void Tour::attaquer(Perso& perso){
    perso.effet_pv(_degat);
}