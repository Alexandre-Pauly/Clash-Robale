all: main 

main: main.o perso.o terrain.o joueur.o sort.o tour.o
	g++ -Wall -o main  main.o perso.o terrain.o joueur.o sort.o tour.o

perso.o: perso.cpp perso.hpp tour.hpp joueur.hpp
	g++ -Wall -c perso.cpp

sort.o: sort.cpp sort.hpp
	g++ -Wall -c sort.cpp

tour.o: tour.cpp tour.hpp perso.hpp joueur.hpp
	g++ -Wall -c tour.cpp

terrain.o: terrain.cpp terrain.hpp perso.hpp tour.hpp sort.hpp
	g++ -Wall -c terrain.cpp

joueur.o: joueur.cpp joueur.hpp
	g++ -Wall -c joueur.cpp


main.o: main.cpp perso.hpp terrain.hpp joueur.hpp sort.hpp tour.hpp
	g++ -Wall -c main.cpp 


clean:
	rm -f *.o 
vclean: clean
	rm -f main