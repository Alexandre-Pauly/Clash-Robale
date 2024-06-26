#ifndef PERSO
#define PERSO

#define NB_CASE 6000
class Tour;
class Joueur;



class Perso{
    public :
    void attaquer(Perso& perso);
    void attaquer(Tour& tour);
    void set_attaque(int state){_attaque=state;}
    int get_attaque()const{return _attaque;}

    void effet_pv(int pv){if(pv+_pv<_pv_max)_pv+=pv; else _pv=_pv_max;}
    int get_pv()const{return _pv;}
    int get_pv_max()const{return _pv_max;}
    void set_pv(int pv){_pv = pv;}
    int get_joueur()const{return _joueur;}
    int get_vitesse()const{return _vitesse;}
    int get_cout()const{return _cout;}
    char get_nom()const{return _nom;}
    int get_range()const{return _range;}

    void add_position(int pos){
        _position += pos;
        if (_position>=NB_CASE)_position=NB_CASE-1;
        if (_position<0)_position=0;
    }
    int get_position()const{return _position;}
    void set_vitesse(int vit){_vitesse = vit;}
    int static const range_vision=NB_CASE/10;
    void add_slowdown(){_slowdown=-4;}
    void rm_slowdown(){_slowdown=0;}
    int get_slowdown()const{return _slowdown;}

    void add_poursuite(){_poursuite=1;}
    void rm_poursuite(){_poursuite=0;}
    int get_poursuite()const{return _poursuite;}


    
    protected :
    char _nom;
    int _attaque;
    int _pv_max;
    int _pv;
    int _degat;
    int _vitesse;
    int _joueur;
    int _cout;
    int _range;
    int _position=0;
    int _slowdown=0;
    int _poursuite=0;
    
};


class Geant:public Perso{
    public:
    Geant(int joueur);
    Geant(const Joueur &joueur);
    

};

class Pekka: public Perso{
    public:
    Pekka(int joueur);
    Pekka(const Joueur &joueur);

};
class Infentrie: public Perso{
    public :
    Infentrie(int joueur);
    Infentrie(const Joueur &joueur);
};




#endif