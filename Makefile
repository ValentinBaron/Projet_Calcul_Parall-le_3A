CXX = /usr/lib64/openmpi/bin/mpic++
CXXFLAGS = -Wall

main: main.o bicgstab.o fonctions.o parametres.o
	$(CXX) main.o bicgstab.o fonctions.o parametres.o -o main

main.o: main.cpp bicgstab.h fonctions.h parametres.h
	$(CXX) $(CXXFLAGS) -c main.cpp

bicgstab.o: bicgstab.cpp bicgstab.h parametres.h
	$(CXX) $(CXXFLAGS) -c bicgstab.cpp

fonctions.o: fonctions.cpp fonctions.h parametres.h
	$(CXX) $(CXXFLAGS) -c fonctions.cpp

parametres.o: parametres.cpp parametres.h
	$(CXX) $(CXXFLAGS) -c parametres.cpp

clean:
	rm -f *.o main