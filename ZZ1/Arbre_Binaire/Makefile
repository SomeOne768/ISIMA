CC = gcc
COMP = -Wall -Wextra -g
OBJ = main.o Arbre.o File.o commun.o Pile.o


prog: $(OBJ)
	$(CC) -o prog $(OBJ) $(COMP)

main.o: main.c Arbre.h
	$(CC) -c main.c $(COMP)

Arbre.o: Arbre.c File.h Pile.h commun.h
	$(CC) -c Arbre.c $(COMP)

File.o: File.c commun.h
	$(CC) -c File.c $(COMP)

commun.o: commun.c
	$(CC) -c commun.c $(COMP)

Pile.o: Pile.c Pile.h
	$(CC) -c Pile.c $(COMP)

clean: 
	rm $(OBJ)