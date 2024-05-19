#include "sort.hpp"
#include "tour.hpp"
#include "joueur.hpp"
#include "perso.hpp"
#include <iostream>


Soin::Soin(int joueur ,int position){
    _temps_effet=100;
    _effet_vie=1;
    _cout=3;
    _effet_sur_joueur=joueur;
    _slowdown=0;
    _zone=NB_CASE/15;
    _position=position;
}
Soin::Soin(const Joueur joueur ,int position){
    _temps_effet=100;
    _effet_vie=1;
    _cout=3;
    _effet_sur_joueur=joueur.get_nb_joueur();
    _slowdown=0;
    _zone=NB_CASE/15;
    _position=position;
}


Poison::Poison(int joueur ,int position){
    _temps_effet=50;
    _effet_vie=-1;
    _cout=3;
    _effet_sur_joueur=(joueur+1)%2;
    _slowdown=1;
    _zone=NB_CASE/15;
    _position=position;
}

Poison::Poison(const Joueur joueur ,int position){
    _temps_effet=50;
    _effet_vie=-1;
    _cout=3;
    _effet_sur_joueur=(joueur.get_nb_joueur()+1)%2;
    _slowdown=1;
    _zone=NB_CASE/30;
    _position=position;
}




Boule_de_feu::Boule_de_feu(int joueur ,int position){
    _temps_effet=1;
    _effet_vie=-80;
    _cout=4;
    _effet_sur_joueur=(joueur+1)%2;
    _slowdown=0;
    _zone=NB_CASE/30;
    _position=position;
}


Boule_de_feu::Boule_de_feu(const Joueur joueur ,int position){
    _temps_effet=1;
    _effet_vie=-100;
    _cout=4;
    _effet_sur_joueur=(joueur.get_nb_joueur()+1)%2;
    _slowdown=0;
    _zone=1;
    _position=position;
}