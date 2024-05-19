#ifndef TERRAIN
#define TERRAIN
#include <vector>
#include <mutex>


class Perso;
class Sort;
class Joueur;

typedef struct{
    char nom;
    int joueur;
    int position;
}ajout_troupe_sort;
extern std::vector<ajout_troupe_sort> tableau_ajout;



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
        void sort_units_by_position();
        void ajout_units();
        void boucle_action(std::mutex * lock_unit, std::mutex * lock_perso);
        int get_pv_tour(int joueur);
        int get_tour_attaque(int joueur);

        
        std::vector<Perso> units;

    private:
        Joueur *_joueurG;
        Joueur *_joueurD;
        std::vector<Sort> sort;
};

#endif