#include "tour.hpp"
#include "joueur.hpp"
#include <iostream>


int Joueur::_nb_joueur=0;
Joueur::Joueur(char* nom, Tour& tour){
    _nom = nom;
    _num_joueur=_nb_joueur;
    _nb_joueur++;
    _tour=&tour;
}
void Joueur::affiche()const{
    std::cout<<"Nom du joueur : "<<_nom<<std::endl;
    std::cout<<"Numero du joueur : "<<_num_joueur<<std::endl;
}