#include "tour.hpp"
#include "joueur.hpp"
#include "terrain.hpp"
#include "sort.hpp"
#include "perso.hpp"
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <mutex>


using namespace std;
std::vector<ajout_troupe_sort> tableau_ajout;

Terrain::Terrain(Joueur & joueurG,Joueur & joueurD){        
    _joueurD=&joueurD;
    _joueurG=&joueurG;

}

void Terrain::sort_units_by_position() {
    std::sort(units.begin(), units.end(), [](const Perso& a, const Perso& b) {
        return a.get_position() < b.get_position();
    });
}


void Terrain::utilisation_sort(Sort s){ //ajout sort dans vecteur sort
    sort.push_back(s);
}

void Terrain::spawn_perso(Perso p,int pos){ //ajout perso dans vecteur units
    p.add_position(pos);
    units.push_back(p);
}


void Terrain::verification_pv(){        //verification de la vie des troupes et supression si plus de pv 
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
    for (int i=0; i<30;i++){
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



bool Terrain::test_proximite(std::vector<Perso>::iterator it) {     // test si une troupe ou une tour adverse est a proximite d'une troupe
    int joueur = it->get_joueur();
    int range = it->get_range();
    int pos=it->get_position();
    if (((pos <= range) && (joueur==1)) || ((pos >= NB_CASE - range - 1) && (joueur==0))) {
        return true;
    }
    if (it->get_nom()!='G')
    {
        for (auto& unit : units) {
            if ((unit.get_joueur()!= joueur) && (unit.get_position() >= std::max(0, pos - range)) && (unit.get_position() < std::min(NB_CASE, pos + range + 1))) {
                    return true;
            }
        }
    }
    return false;
}

bool Terrain::poursuite(std::vector<Perso>::iterator it) {  // verifie si une troupe se trouve proche derrière la troupe afin de la faire suivre
    if (it->get_nom()=='G') return false;
    int joueur = it->get_joueur();
    int range=Perso::range_vision;
    int r=it->get_range()/3;
    int pos=it->get_position();

    if (joueur==0)
    {
        for (auto& unit : units) {

            if ((unit.get_joueur()!= joueur) && (abs(pos-unit.get_position()) <= range) && (unit.get_position() < pos-r)) {
                it->add_position(-(it->get_vitesse()+it->get_slowdown()));
                it->add_poursuite();
                return true;
            }
        }
    }else
    {
        for (auto& unit : units) {
            if ((unit.get_joueur()!= joueur) && (abs(pos-unit.get_position()) <= range) && (unit.get_position() > pos+r))
            {
                it->add_position(it->get_vitesse()+it->get_slowdown());
                it->add_poursuite();
                return true;
            }
        }
    }
    it->rm_poursuite();
    return false;

}


void Terrain::deplacement() {       // gere le deplacement ou non des troupes
    for (auto it = begin(units); it!= end(units); it++) 
    {
        if (!poursuite(it) && !test_proximite(it) )
        {
            if (it->get_joueur() == 0) {
                it->add_position(it->get_vitesse()+it->get_slowdown());
                it->set_attaque(0);
            } else {
                it->add_position(-(it->get_vitesse()+it->get_slowdown()));
                it->set_attaque(0);
            }
        }
    }
}


void Terrain::attaque() {       // attaque troupe ou tour si a proximite
    int range_tour=_joueurD->_tour->_range;
    int g=1, d=1;

    for (auto& unit : units)
    {
        int joueur = unit.get_joueur();
        int range = unit.get_range();
        int pos = unit.get_position();
        
        // attaque des tours sur les personnages
        if ((pos <= range_tour) && unit.get_joueur() && g)
        {
            _joueurG->_tour->attaquer(unit);
            _joueurG->_tour->set_attaque(1);
            g=0;
        }
        if (unit.get_joueur()==0 && (pos >= NB_CASE - range_tour - 1) && d) 
        { 
            _joueurD->_tour->attaquer(unit);
            _joueurD->_tour->set_attaque(1);
            d=0;
        }



        //attaque des personnages
            if ((pos <= range) && unit.get_joueur())
            {
                unit.attaquer(*(_joueurG->_tour));
                unit.set_attaque(1);
            }
            else if (unit.get_joueur()==0 && (pos >= NB_CASE - range - 1)) 
            { 
                unit.attaquer(*(_joueurD->_tour));
                unit.set_attaque(1);
            }else if (unit.get_nom()!='G'){

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
    if (g){
        _joueurG->_tour->set_attaque(0);}
    if (d){
        _joueurD->_tour->set_attaque(0);}

}


void Terrain::effet_sort(){ //applique les sort sur les personnages dans leur zone d'action
    for (auto& unit : units) 
    {
        unit.rm_slowdown();
    }

    for (auto s = sort.begin(); s!= sort.end();) {
        if(s->get_temps()==0){
            s=sort.erase(s);
        }else{
            
            s->reduire_temps();
            int p=s->get_position(), z=s->get_zone();
            for (auto& unit : units) 
            {
                if (unit.get_joueur() == s->get_effet_sur_joueur()) 
                {
                    if (unit.get_position() >= p - z && unit.get_position() <= p + z)
                    {
                        unit.effet_pv(s->get_effet_vie());
                        if (s->get_slowdown())
                        {
                            unit.add_slowdown();
                        }
                    }
                }
            }
            s++;
        }
    }
}


void Terrain::boucle_action(mutex * lock_unit, mutex * lock_perso){     // boucle gerant les actions de tous les persos sur le terrain
    int cpt=0;
    //ajout perso sort?
    while ((_joueurD->_tour->get_pv()>0)&&(_joueurG->_tour->get_pv()>0))
    {
        lock_unit->lock();
        ajout_units();
        lock_unit->unlock();
        lock_perso->lock();
        effet_sort();
        verification_pv();
        deplacement();
        if (cpt==10)
        {
            attaque();
            cpt=0;
        }
        verification_pv();
        lock_perso->unlock();
        //afficher();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        cpt++;

    }
}


int Terrain::get_pv_tour(int joueur){
    if (joueur == 0){
        return _joueurG->_tour->get_pv();
    }
    else{
        return _joueurD->_tour->get_pv();
    }
}

int Terrain::get_tour_attaque(int joueur){
    if (joueur == 0){
        return _joueurG->_tour->get_attaque();
    }
    else{
        return _joueurD->_tour->get_attaque();
    }
}

void Terrain::ajout_units() {       // ajout des persos et sorts grace au tableau_ajout fourni par affichage
    for (auto it = begin(tableau_ajout); it!= end(tableau_ajout); ) {
        switch (it->nom) {
            case 'P':
                spawn_perso(Pekka(it->joueur), it->position);
                it = tableau_ajout.erase(it);
                break;
            case 'G':
                spawn_perso(Geant(it->joueur), it->position);
                it = tableau_ajout.erase(it);
                break;
            case 'I':
                spawn_perso(Infentrie(it->joueur), it->position);
                it = tableau_ajout.erase(it);
                break;
            case 'S':
                utilisation_sort(Soin(it->joueur, it->position));
                it = tableau_ajout.erase(it);
                break;
            case 'T':
                utilisation_sort(Poison(it->joueur, it->position));
                it = tableau_ajout.erase(it);
                break;
            case 'B':
                utilisation_sort(Boule_de_feu(it->joueur, it->position));
                it = tableau_ajout.erase(it);
                break;
            default:
                throw runtime_error("erreur ajout des personnages");
        }
    }
}