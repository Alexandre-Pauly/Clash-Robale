#ifndef TOUR
#define TOUR
class Perso;
class Joueur;

class Tour{
    public :
    Tour();

    void effet_pv(int pv){if(pv<0)_pv+=pv;}
    int get_pv()const {return _pv;}
    void set_pv(int npv){_pv = npv;}
    void attaquer(Perso& perso);
    int _range = 6;
    protected :
    int _pv;
    int _degat;
    
};
#endif