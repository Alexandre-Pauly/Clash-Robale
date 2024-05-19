#ifndef TOUR
#define TOUR
class Perso;
class Joueur;

class Tour{
    public :
    Tour();

    void effet_pv(int pv){if(pv<0)_pv+=pv;}
    int get_pv()const {return _pv;}
    int get_pv_max()const {return _pv_max;}
    void set_pv(int npv){_pv = npv;}
    void attaquer(Perso& perso);
    void set_attaque(int state){_attaque=state;}
    int get_attaque()const{return _attaque;}
    int _range = 6;
    protected :
    int _attaque;
    int _pv;
    int _pv_max=125;
    int _degat;
    
};
#endif