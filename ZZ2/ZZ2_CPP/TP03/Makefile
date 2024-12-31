COMP = g++
FLAGS = -Wall -Wextra
OBJ = main.o Famille.o Bavarde.o Couple.o Fille.o Mere.o

prog: main.o Famille.o Bavarde.o Couple.o Fille.o Mere.o 
	$(COMP) -o prog $(OBJ) $(FLAGS)

main.o: main.cpp Famille.hpp Bavarde.hpp Couple.hpp Fille.hpp Mere.hpp
	$(COMP) -c main.cpp Famille.hpp Bavarde.hpp Couple.hpp Fille.hpp Mere.hpp $(FLAGS)

Famille.o: Famille.cpp Famille.hpp
	$(COMP) -c Famille.cpp  $(FLAGS)

Mere.o: Mere.hpp Mere.cpp 
	$(COMP) -c Mere.cpp  $(FLAGS)

Fille.o: Fille.hpp Fille.cpp Mere.o
	$(COMP) -c Fille.cpp   $(FLAGS)

Bavarde.o: Bavarde.hpp Bavarde.cpp
	$(COMP) -c Bavarde.cpp   $(FLAGS)

Couple.o: Bavarde.hpp Couple.hpp Couple.cpp 
	$(COMP) -c Couple.cpp Bavarde.hpp   $(FLAGS)


clean:
	rm -rf $(OBJ)