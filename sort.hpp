#ifndef SORT
#define SORT

class Joueur;
class Sort{
    public:
        void reduire_temps(){_temps_effet--;}
        int get_temps(){return _temps_effet;}
        int get_effet_vie(){return _effet_vie;}
        int get_cout(){return _cout;}
        int get_effet_sur_joueur(){return _effet_sur_joueur;}
        int get_slowdown(){return _slowdown;}
        int get_zone(){return _zone;}
        int get_position(){return _position;}

    protected:
        int _temps_effet;
        int _effet_vie;
        int _cout;
        int _effet_sur_joueur;
        int _slowdown;
        int _zone;
        int _position;
};

class Soin:public Sort{
    public:
    Soin(int joueur ,int position);
    Soin(const Joueur joueur ,int position);
};

class Poison:public Sort{
    public:
    Poison(int joueur ,int position);
    Poison(const Joueur joueur ,int position);
};

class Boule_de_feu:public Sort{
    public:
    Boule_de_feu(int joueur ,int position);
    Boule_de_feu(const Joueur joueur ,int position);
};

#endif
