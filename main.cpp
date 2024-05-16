#include "sort.hpp" 
#include "tour.hpp"
#include "joueur.hpp"
#include "perso.hpp"
#include "terrain.hpp"
#include <iostream>
#include <chrono>
using namespace std;



int main() {
    // Début du chrono
    auto start = std::chrono::high_resolution_clock::now();

    // Votre code ici
    std::vector<ajout_troupe_sort> tableau_ajout;
    char str[50]="gauche";
    Tour *T1=new Tour;
    Tour *T2=new Tour;
    Joueur joueurG(str,*T1);
    char str2[50]="droite";
    Joueur joueurD(str2,*T2);
    Terrain terrain(joueurG,joueurD);
    Pekka Pekka(joueurD);
    Geant Geant(joueurG);
    Infentrie Infentrie(joueurD);



    Boule_de_feu Boule_de_feu(joueurD,11);
    Poison Poison(0,10);
    Soin soin(joueurD,12);



    //terrain.utilisation_sort(Boule_de_feu);
    //terrain.utilisation_sort(Poison);
    //terrain.spawn_perso(Infentrie,28);
    terrain.spawn_perso(&Pekka,15);
    terrain.spawn_perso(&Geant,20);
    terrain.spawn_perso(&Infentrie,28);

    terrain.afficher();
    //terrain.boucle_action(4);

    // Fin du chrono
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // Affichage du temps d'exécution
    std::cout << "Temps d'exécution : " << elapsed.count() << " secondes" << std::endl;

    return 0;
}