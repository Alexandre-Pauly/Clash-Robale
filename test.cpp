#define CATCH_CONFIG_MAIN
#include "tour.hpp"
#include "joueur.hpp"
#include "terrain.hpp"
#include "sort.hpp"
#include "perso.hpp"
#include "catch.hpp"


    char str[50]="gauche";
    char str2[50]="droite";
    Tour *T1=new Tour;
    Tour *T2=new Tour;
    Joueur joueurG(str,*T1);
    Joueur joueurD(str2,*T2);


TEST_CASE("Constructeur"){
    Geant G0(0);                //verifictions valeurs a initialisation
    REQUIRE(G0.get_nom() == 'G');
    REQUIRE(G0.get_joueur()==0);
    REQUIRE(G0.get_pv()==200);


    REQUIRE(T1->get_pv()==600);


    REQUIRE(joueurG.get_nb_joueur()==0);
    REQUIRE(joueurD.get_nb_joueur()==1);

    Pekka P1(joueurD);
    REQUIRE(P1.get_nom() == 'P');
    REQUIRE(P1.get_joueur()==1);
    REQUIRE(P1.get_pv()==100);

    Soin s0(0,24);
    REQUIRE(s0.get_effet_sur_joueur()==0);
    REQUIRE(s0.get_position()==24);

    Boule_de_feu b1(joueurD,12);
    REQUIRE(b1.get_effet_sur_joueur()==0);
    REQUIRE(b1.get_position()==12);

}

TEST_CASE("Attaque perso/tour"){
    Tour t;
    
    Geant G0(0);
    Pekka P1(1);

    t.attaquer(P1);
    P1.attaquer(G0);
    G0.attaquer(t);

    REQUIRE(P1.get_pv()==P1.get_pv_max()-4);
    REQUIRE(G0.get_pv()==G0.get_pv_max()-6);
    REQUIRE(t.get_pv()==t.get_pv_max()-4);      //verification pv après attaque
}


TEST_CASE("test jeu"){
    
    Terrain terrain(joueurG,joueurD);

    Geant G0(joueurG);
    Pekka P1(joueurD);
    Infentrie I1(joueurD);

    Boule_de_feu bdf(joueurD,323);

    terrain.spawn_perso(G0,322);
    terrain.spawn_perso(P1,324);
    terrain.spawn_perso(I1,1200);
    terrain.utilisation_sort(bdf);
    terrain.effet_sort();


    int pv_G =terrain.units.at(0).get_pv();
    REQUIRE(pv_G==G0.get_pv_max()+bdf.get_effet_vie());     //degat boule de feu

    terrain.attaque();
    REQUIRE(terrain.units.at(0).get_pv()==pv_G-6);      //attaque par pekka
    REQUIRE(terrain.units.at(1).get_pv()==P1.get_pv_max()-4);       //attaque par tour

    terrain.deplacement();
    REQUIRE(terrain.units.at(0).get_position()==322+G0.get_vitesse());  // n'attaque pas les troupes
    REQUIRE(terrain.units.at(1).get_position()==324);           //attaque le geant donc ne bouge pas
    REQUIRE(terrain.units.at(2).get_position()==1200-I1.get_vitesse());     //n'attaque pas car trop loin donc avance


}
