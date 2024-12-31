COMP = g++
FLAGS = -Wall -Wextra
OBJ = main.o A.o B.o

prog: $(OBJ)
	$(COMP) -o prog $(OBJ) $(FLAGS) 

main.o: main.cpp A.hpp B.hpp 
	$(COMP) -c main.cpp A.hpp B.hpp $(FLAGS)

A.o: A.hpp A.cpp B.hpp 
	$(COMP) -c A.cpp B.hpp $(FLAGS)

B.o: B.hpp B.cpp A.hpp
	$(COMP) -c B.cpp A.hpp $(FLAGS)

clean: 
	rm -rf $(OBJ)