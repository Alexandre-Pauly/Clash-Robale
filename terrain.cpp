#include "tour.hpp"
#include "joueur.hpp"
#include "terrain.hpp"
#include "sort.hpp"
#include "perso.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

Terrain::Terrain(Joueur & joueurG,Joueur & joueurD){
    _joueurD=&joueurD;
    _joueurG=&joueurG;

}

void Terrain::sort_units_by_position() {
    std::sort(units.begin(), units.end(), [](const Perso& a, const Perso& b) {
        return a.get_position() < b.get_position();
    });
}


void Terrain::utilisation_sort(Sort &s){
    sort.push_back(s);
}

void Terrain::spawn_perso(Perso &p,int pos){
    p.add_position(pos);
    units.push_back(p);
}


void Terrain::verification_pv(){
    for (auto it = begin (units); it != end (units); ) {
        if(it->get_pv()<=0){
            it=units.erase(it);
        }else{
            ++it;
        }
    }
}

void Terrain::afficher()const{
    cout<<"Tour gauche  PV= "<<_joueurG->_tour->get_pv()<<"\n";
    for (int i=0; i<NB_CASE;i++){
        cout<<i<<": ";
        for (auto& unit : units) {
            if (unit.get_position() == i) {
                cout << unit.get_nom() << ": "<<unit.get_pv()<<"   j"<<unit.get_joueur()+1;
                cout << "   ";
            }
        }
        cout << "\n";
    }
    cout<<"Tour droite  PV= "<<_joueurD->_tour->get_pv()<<"\n";
    cout << endl;
}



bool Terrain::test_proximite(std::vector<Perso>::iterator it) {
    int joueur = it->get_joueur();
    int range = it->get_range();
    int pos=it->get_position();
    if (((pos <= range) && (joueur==1)) || ((pos >= NB_CASE - range - 1) && (joueur==0))) {
        return true;
    }
    for (auto& unit : units) {
        if (unit.get_position() >= std::max(0, pos - range) && unit.get_position() < std::min(NB_CASE, pos + range + 1)) {
            if (unit.get_joueur()!= joueur) {
                return true;
            }
        }
    }
    return false;
}


void Terrain::deplacement() {
    for (auto it = begin(units); it!= end(units); it++) 
    {
        if (!test_proximite(it))
        {
            if (it->get_joueur() == 0) {
                it->add_position(it->get_vitesse());
                it->set_attaque(0);
            } else {
                it->add_position(-it->get_vitesse());
                it->set_attaque(0);
            }
        }
    }
}


void Terrain::attaque() {
    for (auto& unit : units) 
    {
        int joueur = unit.get_joueur();
        int range = unit.get_range();
        int pos = unit.get_position();
        if ((pos <= range) && unit.get_joueur())
        {
            unit.attaquer(*(_joueurG->_tour));
            unit.set_attaque(1);
        }
        else if (unit.get_joueur()==0 && (pos >= NB_CASE - range - 1)) 
        { 
            unit.attaquer(*(_joueurD->_tour));
            unit.set_attaque(1);
        }else{

            for (auto& other_unit : units) {
                if (other_unit.get_joueur()!= joueur){
                    if (other_unit.get_position() >= std::max(0, pos - range) && other_unit.get_position() < std::min(NB_CASE, pos + range + 1)) {
                        unit.attaquer(other_unit);
                        unit.set_attaque(1);
                        break;
                    }
                }
            }
        }
    }
}


void Terrain::effet_sort(){
    for (auto s = sort.begin(); s!= sort.end();) {
        if(s->get_temps()==0){
            s=sort.erase(s);
        }else{
            
            s->reduire_temps();
            int p=s->get_position(), z=s->get_zone();
            for (auto& unit : units) {
                if (unit.get_position() >= p - z && unit.get_position() <= p + z) {
                    if (unit.get_joueur() == s->get_effet_sur_joueur()) {
                        unit.effet_pv(s->get_effet_vie());
                    }
                }
            }
            s++;
        }
    }
}




void Terrain::boucle_action(int n){
    //ajout perso sort?
    for (int i=0; i<n;i++)
    {
        effet_sort();
        verification_pv();
        deplacement();
        attaque();
        verification_pv();
        afficher();
    }
}

void Terrain::ajout_units(){
    
}