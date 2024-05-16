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
    
    char str[50]="gauche";
    Tour *T1=new Tour;
    Tour *T2=new Tour;
    Joueur joueurG(str,*T1);
    char str2[50]="droite";
    Joueur joueurD(str2,*T2);
    Terrain terrain(joueurG,joueurD);

    
    //terrain.afficher();
    terrain.boucle_action(4);

    // Fin du chrono
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // Affichage du temps d'exécution
    std::cout << "Temps d'exécution : " << elapsed.count() << " secondes" << std::endl;

    return 0;
}