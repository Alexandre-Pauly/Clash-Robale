all: clash_Robale


perso.o: perso.cpp perso.hpp tour.hpp joueur.hpp
	g++ -Wall -g -c perso.cpp

sort.o: sort.cpp sort.hpp
	g++ -Wall -g -c sort.cpp

tour.o: tour.cpp tour.hpp perso.hpp joueur.hpp
	g++ -Wall -g -c tour.cpp

terrain.o: terrain.cpp terrain.hpp perso.hpp tour.hpp sort.hpp
	g++ -Wall -g -c terrain.cpp

joueur.o: joueur.cpp joueur.hpp
	g++ -Wall -g -c joueur.cpp


clash_Robale: affichage.cpp perso.o terrain.o joueur.o sort.o tour.o
	g++ -g affichage.cpp -o clash_Robale -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio perso.o terrain.o joueur.o sort.o tour.o

test: test.cpp perso.o terrain.o joueur.o sort.o tour.o
	g++ test.cpp -o test perso.o terrain.o joueur.o sort.o tour.o


clean:
	rm -f *.o 
vclean: clean
	rm -f clash_Robale test