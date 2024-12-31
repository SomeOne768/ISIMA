CC = gcc
COMP = -Wall -Wextra -g
OBJ = structure.o listecontigue.o main.o
EXE = prog


prog: main.o structure.o listecontigue.o
	$(CC) -o prog main.o structure.o listecontigue.o $(COMP)
	@echo "\nLancer le programme avec \"./prog FichierExemple\""
	@echo "La compilation se fait avec l'option '-g', vous pouvez donc utiliser valgrind.\n"

main.o: main.c structure.h listecontigue.h
	$(CC) -c main.c $(COMP)

structure.o: structure.h structure.c
	$(CC) -c structure.c $(COMP)

listecontigue.o: listecontigue.h listecontigue.c structure.h
	$(CC) -c listecontigue.c $(COMP)

clean:
	rm $(OBJ)

cleanExe:
	rm $(EXE)