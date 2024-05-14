#ifndef JOUEUR
#define JOUEUR
#include <vector>

class Tour;
class Perso;


class Joueur{
    
    public:
        Joueur(){};
        Joueur(char* nom,Tour& tour);
        void affiche()const;
        int get_nb_joueur()const{return _num_joueur;}
        Tour *_tour;
    private:
        static int _nb_joueur;
        int _num_joueur;
        char* _nom;

};

#endif