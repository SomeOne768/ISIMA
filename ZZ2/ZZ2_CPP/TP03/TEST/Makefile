COMP = g++
FLAGS = -Wall -Wextra
OBJ = main.o
prog: $(OBJ)
	$(COMP) -o prog $(OBJ) $(FLAGS) 

main.o: main.cpp  
	$(COMP) -c main.cpp $(FLAGS)


clean: 
	rm -rf $(OBJ)