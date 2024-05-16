#ifndef TERRAIN
#define TERRAIN
#include <vector>


class Perso;
class Sort;
class Joueur;

typedef struct{
    char nom;
    int joueur;
    int position;
}ajout_troupe_sort;



class Terrain{
    public:
        Terrain(Joueur & joueurG,Joueur & joueurD);
        ~Terrain(){}
        void verification_pv();
        void deplacement();
        bool test_proximite(std::vector<Perso>::iterator it);
        void attaque();
        void afficher()const;
        void spawn_perso(Perso *p,int pos);
        void utilisation_sort(Sort *s);
        void effet_sort();
        void boucle_action(int n);
        void sort_units_by_position();
        void ajout_units();

        
        std::vector<Perso> units;

    private:
        Joueur *_joueurG;
        Joueur *_joueurD;
        std::vector<Sort> sort;
};

#endif