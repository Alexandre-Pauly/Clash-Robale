#include "sort.hpp"
#include "tour.hpp"
#include "joueur.hpp"

Soin::Soin(int joueur ,int position){
    _temps_effet=4;
    _effet_vie=3;
    _cout=3;
    _effet_sur_joueur=joueur;
    _slowdown=0;
    _zone=2;
    _position=position;
}
Soin::Soin(const Joueur joueur ,int position){
    _temps_effet=4;
    _effet_vie=3;
    _cout=3;
    _effet_sur_joueur=joueur.get_nb_joueur();
    _slowdown=0;
    _zone=2;
    _position=position;
}


Poison::Poison(int joueur ,int position){
    _temps_effet=4;
    _effet_vie=-2;
    _cout=3;
    _effet_sur_joueur=(joueur+1)%2;
    _slowdown=2;
    _zone=2;
    _position=position;
}

Poison::Poison(const Joueur joueur ,int position){
    _temps_effet=4;
    _effet_vie=-2;
    _cout=3;
    _effet_sur_joueur=(joueur.get_nb_joueur()+1)%2;
    _slowdown=2;
    _zone=2;
    _position=position;
}




Boule_de_feu::Boule_de_feu(int joueur ,int position){
    _temps_effet=1;
    _effet_vie=-8;
    _cout=4;
    _effet_sur_joueur=(joueur+1)%2;
    _slowdown=0;
    _zone=1;
    _position=position;
}


Boule_de_feu::Boule_de_feu(const Joueur joueur ,int position){
    _temps_effet=1;
    _effet_vie=-8;
    _cout=4;
    _effet_sur_joueur=(joueur.get_nb_joueur()+1)%2;
    _slowdown=0;
    _zone=1;
    _position=position;
}