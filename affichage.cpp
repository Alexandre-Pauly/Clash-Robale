#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "sort.hpp" 
#include "tour.hpp"
#include "joueur.hpp"
#include "perso.hpp"
#include "terrain.hpp"
#include <chrono>
using namespace std;

// truc a faire, pour faire un projet plus propre
//tout mettre  dans une class affichage, comme ca on peut faire communiquerla classe terrain avec la class affichage. 
// mettre toute les images dans les dossiers bien rangé sinon c'est illisible et le truc est impossible a rendre.
// but a faire lundi : faire deux thread qui communique entre eux a l'aide d'observateur, et effectivement en poo c'est plus simple de communiquer. 
// record des bruit pour les mort/ tire/ attaque/spawn ??? j'ai trop d'idee je trouve je dois dormir. 
//azzi c'est long eft j'ai plein de taf.
// fonction manque d'elexir

int affichage(Terrain* terrain)
{
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Clash Robal !");
    int hz = 144;
    window.setFramerateLimit(hz);
    sf::Texture fond;
    sf::Texture tour1;
    sf::Texture tour2;
    sf::Texture fleche1;
    sf::Texture fleche2;
    sf::Texture titre;
    sf::Texture fond_vie_tour;
    sf::Texture vie_tour_vert;
    sf::Texture vie_tour_jaune;
    sf::Texture vie_tour_orange;
    sf::Texture vie_tour_rouge;
    sf::Texture toucheJ1;
    sf::Texture toucheJ2;
    sf::Texture BDF1;
    sf::Texture Heal;
    sf::Texture Poison;
    sf::Texture fond_elexir;
    sf::Texture telexir;
    sf::Texture geant;
    sf::Texture geant2;
    
    //Chargement des textures du jeu
    fond.loadFromFile("element_fixe/fond.jpg", sf::IntRect(0,0, 1920,1080));
    toucheJ1.loadFromFile("element_fixe/toucheJ1.png");
    toucheJ2.loadFromFile("element_fixe/toucheJ2.png");
    tour1.loadFromFile("element_fixe/tour1.png", sf::IntRect(100, 0, 500, 500));
    tour2.loadFromFile("element_fixe/tour2.png", sf::IntRect(0, 0, 500, 500));
    fleche1.loadFromFile("fleche_arg.png", sf::IntRect(0, 0, 100, 120));
    fleche2.loadFromFile("fleche.png", sf::IntRect(0, 0, 100, 120));
    titre.loadFromFile("element_fixe/titre.png", sf::IntRect(0,0,814,360));
    BDF1.loadFromFile("sort/bdf.png");
    Heal.loadFromFile("sort/heal.png");
    Poison.loadFromFile("sort/poison.png");
    // Chargement des barres de vie (differentes couleurs)
    fond_vie_tour.loadFromFile("vie_tour/fond.png", sf::IntRect(0,0,215,39));
    fond_elexir.loadFromFile("barre_elexir/elexir_empty.png");
    telexir.loadFromFile("barre_elexir/elexir_full.png");

    vie_tour_vert.loadFromFile("vie_tour/vert.png", sf::IntRect(0,0,215,39));
    vie_tour_jaune.loadFromFile("vie_tour/jaune.png", sf::IntRect(0,0,215,39));
    vie_tour_orange.loadFromFile("vie_tour/orange.png", sf::IntRect(0,0,215,39));
    vie_tour_rouge.loadFromFile("vie_tour/rouge.png", sf::IntRect(0,0,215,39));
    

    geant.loadFromFile("perso/geant/walking.png");
    geant2.loadFromFile("perso/geant/walking2.png");
    //Creation des sprites des elements graphiques
    sf::Sprite sfond;
    sfond.setTexture(fond);
    sfond.setPosition(sf::Vector2f(0, 0));

    sf::Sprite stoucheJ1;
    stoucheJ1.setTexture(toucheJ1);
    stoucheJ1.setPosition(sf::Vector2f(10, 10));
    stoucheJ1.setScale(sf::Vector2f(0.8f, 0.8f));

    sf::Sprite stoucheJ2;
    stoucheJ2.setTexture(toucheJ2);
    stoucheJ2.setPosition(sf::Vector2f(1300, 10));
    stoucheJ2.setScale(sf::Vector2f(0.8f, 0.8f));

    sf::Sprite stour1;
    stour1.setTexture(tour1);
    stour1.setPosition(sf::Vector2f(0, 630.f));
    stour1.setScale(sf::Vector2f(0.5f, 0.5f));

    sf::Sprite stour2;
    stour2.setTexture(tour2);
    stour2.setPosition(sf::Vector2f(1710.f, 640.f));
    stour2.setScale(sf::Vector2f(0.5f, 0.5f));

    sf::Sprite sfleche1;
    sfleche1.setTexture(fleche1);
    sfleche1.setRotation(-90);

    sf::Sprite sfleche2;
    sfleche2.setTexture(fleche2);
    sfleche2.setRotation(-90);

    sf::Sprite stitre; 
    stitre.setTexture(titre);
    stitre.setPosition(sf::Vector2f(730,0));
    stitre.setScale(sf::Vector2f(0.5f, 0.5f));
    //vie tour
    sf::Sprite sfvt1; //fond vie tour
    sfvt1.setTexture(fond_vie_tour);
    sfvt1.setPosition(sf::Vector2f(10,600));

    sf::Sprite svt1; //vie tour
    svt1.setTexture(vie_tour_vert);
    svt1.setPosition(sf::Vector2f(10,604));

    sf::Sprite sfvt2; //fond vie tour
    sfvt2.setTexture(fond_vie_tour);
    sfvt2.setPosition(sf::Vector2f(1700,600));

    sf::Sprite svt2; //vie tour 2
    svt2.setTexture(vie_tour_vert);
    svt2.setPosition(sf::Vector2f(1700,604));
    // elexir
    sf::Sprite sel1; //elexir1
    sel1.setTexture(telexir);
    sel1.setPosition(sf::Vector2f(35,200));
    sel1.setScale(sf::Vector2f(0.6f, 0.6f));
    

    sf::Sprite sfel1; //fond elexir 1
    sfel1.setTexture(fond_elexir);
    sfel1.setPosition(sf::Vector2f(35,200));
    sfel1.setScale(sf::Vector2f(0.6f, 0.6f));
    

    sf::Sprite sel2; //elexir2
    sel2.setTexture(telexir);
    sel2.setPosition(sf::Vector2f(1370,200));
    sel2.setScale(sf::Vector2f(0.6f, 0.6f));

    sf::Sprite sfel2; //fond elexir 2
    sfel2.setTexture(fond_elexir);
    sfel2.setPosition(sf::Vector2f(1370,200));
    sfel2.setScale(sf::Vector2f(0.6f, 0.6f));

    // sort les sort sont "affiné" dans la boucle while
    sf::Sprite sbdf; //boule de feu
    sbdf.setTexture(BDF1);
    sbdf.setRotation(90);

    sf::Sprite sheal; //soin 
    sheal.setTexture(Heal);

    sf::Sprite spoison; //soin 
    spoison.setTexture(Poison);
    spoison.setScale(sf::Vector2f(1.5f, 1.5f));

    // les persos, sont egalement affiné a la fin
    sf::Sprite sgeant;
    sgeant.setTexture(geant);

    sf::Sprite sgeant2;
    sgeant2.setTexture(geant2);



    sf::Music mTheme;
    if (!mTheme.openFromFile("sound_effect/music/Glorious_Morning.wav"))
        return -1; // error
    mTheme.play();
    mTheme.setLoop(true);
    int Nombre_de_case = 30 ;
    int position_J1 = 0;
    int position_J2 = Nombre_de_case -1;


    //a retirer plus tard une fois que je fais le lien avec alex
    int HP_Max_Tour=100;
    int pvJ1 = 100;
    int lpvJ1 =100;
    int pvJ2 = 100;
    int lpvJ2 =100;
    int compteur=0;
    float elexir1=0;
    float elexir2=0;

    //creation des boules de feu (4 max)
    int BDF [4][2];
    for (int k=0;k<4;k++){
        for (int j=0;j<2;j++){
            BDF[k][j]= 0;
        }
    }
    int heal [4][2];
    for (int k=0;k<4;k++){
        for (int j=0;j<2;j++){
            heal[k][j]= 4*hz;
        }
    }
    int poison [4][2];
    for (int k=0;k<4;k++){
        for (int j=0;j<2;j++){
            poison[k][j]= 6*120;
        }
    }



    while (window.isOpen())
    {
        compteur++;
        if(elexir1<10){elexir1 +=1/float(hz);}
        sel1.setTextureRect(sf::IntRect(0, 0, int(elexir1*(86)), 45));
        if(elexir2<10){elexir2 +=1/float(hz);}
        sel2.setTextureRect(sf::IntRect(0, 0, int(elexir2*(86)), 45));
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                std::cout<< "hello"<<std::endl;
                // LES LIGNES SI DESSOUS FONT BOUGER LES FLECHES
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
                    if (position_J1<(Nombre_de_case)){
                    position_J1+=Nombre_de_case/30;
                    std::cout<< position_J1 <<std::endl;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                    if (position_J1>0){
                    position_J1-= Nombre_de_case/30;
                    std::cout<< position_J1 <<std::endl;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon)){
                    if (position_J2<(Nombre_de_case)){
                    position_J2+=Nombre_de_case/30;
                    std::cout<< position_J2 <<std::endl;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma)){
                    if (position_J2>0){
                    position_J2-=Nombre_de_case/30;
                    std::cout<< position_J2 <<std::endl;
                    }
                }

                // comme ca je peux tester si ca marche
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    if (pvJ1>0){
                    pvJ1--;
                    }}
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
                    if (pvJ2>0){
                    pvJ2--;
                    }}

                //////////////////////////
                //spawn des troupes
                //////////////////////////
                ///joueur 1 
                // infentrie
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    if(elexir1>3){
                        if (position_J1<=Nombre_de_case/3){
                            elexir1-=3;
                            ajout_troupe_sort i;
                            i.nom = 'i';
                            i.joueur = 0;
                            i.position = position_J1;
                            tableau_ajout.push_back(i);
                            }
                    }
                }
                //pekka
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
                    if(elexir1>3){
                        if (position_J1<=Nombre_de_case/3){
                            elexir1-=3;
                            ajout_troupe_sort p;
                            p.nom = 'p';
                            p.joueur = 0;
                            p.position = position_J1;
                            tableau_ajout.push_back(p);
                            
                            }
                    }
                }
                //geant
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
                    if(elexir1>4){
                        if (position_J1<=Nombre_de_case/3){
                            elexir1-=4;
                            ajout_troupe_sort g;
                            g.nom = 'g';
                            g.joueur = 0;
                            g.position = position_J1;
                            tableau_ajout.push_back(g);
                            
                            }
                    }
                }
                ///////// Troupe joueur 2
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)){
                    if(elexir2>3){
                        if (position_J2>=(Nombre_de_case*2)/3){
                            elexir2-=3;
                            ajout_troupe_sort i;
                            i.nom = 'i';
                            i.joueur = 1;
                            i.position = position_J2;
                            tableau_ajout.push_back(i);
                            }
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
                    if(elexir2>3){
                        if (position_J2<=(2*Nombre_de_case)/3){
                            elexir2-=3;
                            ajout_troupe_sort p;
                            p.nom = 'p';
                            p.joueur = 1;
                            p.position = position_J2;
                            tableau_ajout.push_back(p);
                            
                            }
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
                    if(elexir2>4){
                        if (position_J2<=(2*Nombre_de_case)/3){
                            elexir2-=4;
                            ajout_troupe_sort g;
                            g.nom = 'g';
                            g.joueur = 1;
                            g.position = position_J2;
                            tableau_ajout.push_back(g);
                            
                            }
                    }
                }







                ////////////////////////
                /////////spawn des sorts
                ///////////////////////
                // detection des Boule de feu
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    if(elexir1>4){
                    elexir1-=4;
                    if(BDF[0][1]!=0){
                        BDF[1][0]=position_J1;
                        BDF[1][1]=100;}
                    else{
                        BDF[0][0]=position_J1;
                        BDF[0][1]=100;}
                    }
                    }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
                    if(elexir2>4){
                    elexir2-=4;
                    if(BDF[2][1]!=0){
                        BDF[3][0]=position_J2;
                        BDF[3][1]=100;}
                    else{
                        BDF[2][0]=position_J2;
                        BDF[2][1]=100;}
                    }
                    }
                // detection des sorts de heal
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                    if(elexir1>3){
                    elexir1-=3;                    
                    if(heal[0][1]!=4*hz){
                        heal[1][0]=position_J1;
                        heal[1][1]=0;}
                    else{
                        heal[0][0]=position_J1;
                        heal[0][1]=0;}
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
                    if(elexir2>3){
                    elexir2-=3;                    
                    if(heal[2][1]!=4*hz){
                        heal[3][0]=position_J2;
                        heal[3][1]=0;}
                    else{
                        heal[2][0]=position_J2;
                        heal[2][1]=0;}
                    }
                }
                //sort de poison
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                    if(elexir1>3){
                    elexir1-=3;                    
                    if(poison[0][1]!=6*120){
                        poison[1][0]=position_J1;
                        poison[1][1]=0;}
                    else{
                        poison[0][0]=position_J1;
                        poison[0][1]=0;}
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
                    if(elexir2>3){
                    elexir2-=3;                    
                    if(poison[2][1]!=6*120){
                        poison[3][0]=position_J2;
                        poison[3][1]=0;}
                    else{
                        poison[2][0]=position_J2;
                        poison[2][1]=0;}
                    }
                }
            }
        // Si la vie du J1 est differente d'avant, on change l'affichage de sa vie     
        }
        if (pvJ1!=lpvJ1){
            lpvJ1 = pvJ1;
            svt1.setTextureRect(sf::IntRect(0, 0, pvJ1*(215/HP_Max_Tour), 35));
            if (100*pvJ1/HP_Max_Tour==70){
                svt1.setTexture(vie_tour_jaune);
            }
            if (100*pvJ1/HP_Max_Tour==40){
                svt1.setTexture(vie_tour_orange);
                svt1.setPosition(sf::Vector2f(10,602));
            }
            if (100*pvJ1/HP_Max_Tour==20){
                svt1.setTexture(vie_tour_rouge);
                svt1.setPosition(sf::Vector2f(10,600));
            }}
        if (pvJ2!=lpvJ2){
            lpvJ2 = pvJ2;
            svt2.setTextureRect(sf::IntRect(0, 0, pvJ2*(215/HP_Max_Tour), 35));
            if (100*pvJ2/HP_Max_Tour==70){
                svt2.setTexture(vie_tour_jaune);
            }
            if (100*pvJ2/HP_Max_Tour==40){
                svt2.setTexture(vie_tour_orange);
                svt2.setPosition(sf::Vector2f(1700,602));
            }
            if (100*pvJ1/HP_Max_Tour==20){
                svt2.setTexture(vie_tour_rouge);
                svt2.setPosition(sf::Vector2f(1700,600));
            }}
        
        

        window.clear();
        //les objets statiques
        window.draw(sfond);
        window.draw(stoucheJ1);
        window.draw(stoucheJ2);
        window.draw(sfel1);
        window.draw(sfel2);
        window.draw(sel1);
        window.draw(sel2);
        window.draw(stour1);
        window.draw(stour2);
        window.draw(stitre);
        window.draw(sfvt1);
        window.draw(sfvt2);
        window.draw(svt1);
        window.draw(svt2);

        ////////////////les objets qui bougent
        //les fleches 
        sfleche1.setPosition(sf::Vector2f(160 + position_J1*(1500/Nombre_de_case),920));
        window.draw(sfleche1);
        sfleche2.setPosition(sf::Vector2f(160 + position_J2*(1500/Nombre_de_case),920));
        window.draw(sfleche2);

        //les sorts
        //boule de feu
        //affichage des Boules de feu
        for (int k=0;k<4;k++){
            if (BDF[k][1]>0){
                sbdf.setTextureRect(sf::IntRect(153*(BDF[k][1]%6),0,153,154));
                sbdf.setPosition(sf::Vector2f(313 + BDF[k][0]*(1500/Nombre_de_case),774-BDF[k][1]*8));
                window.draw(sbdf);
                BDF[k][1]--;
                if (BDF[k][1]==1){
                    
                }
                }
            }
        // affichage du sort de heal
        for (int k=0;k<4;k++){
            if (heal[k][1]<4*hz){
                if (heal[k][1]<100){
                    sheal.setTextureRect(sf::IntRect(192*(int(heal[k][1]/10)%5),130*(int(heal[k][1]/50)%2),183,167));
                    sheal.setPosition(sf::Vector2f(154 + heal[k][0]*(1500/Nombre_de_case),760-(int(heal[k][1]/50)%2)*60));}
                else{
                    sheal.setTextureRect(sf::IntRect(192*(int(heal[k][1]/10)%5),167*2,153,154));
                    sheal.setPosition(sf::Vector2f(154 + heal[k][0]*(1500/Nombre_de_case),710));}
                window.draw(sheal);
                heal[k][1]++;
                if (heal[k][1]==1){
                    ajout_troupe_sort h;
                    h.nom = 's';
                    h.joueur = k/2;
                    h.position = heal[k][0];
                    tableau_ajout.push_back(h);
                }
                }
            }
        for (int k=0;k<4;k++){
            if (poison[k][1]<6*120){              
                spoison.setTextureRect(sf::IntRect(110*(int(poison[k][1]/20)%6),150*(int(poison[k][1]/120)%2),110,122));
                spoison.setPosition(sf::Vector2f(160 + poison[k][0]*(1500/Nombre_de_case),700));
                window.draw(spoison);
                poison[k][1]++;
                if (poison[k][1]==1){
                    //envoyer info au jeu
                }
                }
            }
        //////////////// affichage des personnages 

        int n = sizeof(terrain->units);
        for (int k=0;k<n;k++){
            //affichage des geants
            if (terrain->units[k].get_nom() == 'G'){
                if (terrain->units[k].get_joueur()==1){
                sgeant.setTextureRect(sf::IntRect(202*((compteur/10)%5),184*((compteur/50)%8),202,184));
                sgeant.setPosition(sf::Vector2f(154 + terrain->units[k].get_position()*(1500/Nombre_de_case),650));
                window.draw(sgeant);
                }
                else {
                    sgeant2.setTextureRect(sf::IntRect(808- 202*((compteur/10)%5),184*((compteur/50)%8),202,184));
                    sgeant2.setPosition(sf::Vector2f(154 + terrain->units[k].get_position()*(1500/Nombre_de_case),650));
                    std::cout<< terrain->units[k].get_position()<<std::endl;
                    
                    window.draw(sgeant2);}

                }

                
            
            //affichage des infentries
            if (terrain->units[k].get_nom() == 'i'){

            }
            if (terrain->units[k].get_nom() == 'p'){
            }
        }
        
        



        // on code au dessus de ca
        window.display();

    }

    return 0;
}

int main(){
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
    Geant geant(joueurD);
    Geant geant2(joueurG);
    terrain.spawn_perso(&geant,0);
    terrain.spawn_perso(&geant2,29);

    affichage(&terrain);
    return 0;
}