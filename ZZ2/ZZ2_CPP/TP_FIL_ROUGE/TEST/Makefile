# utilise le compilo par defaut de la machine
CXX=g++
SRC=main.cpp Cercle.cpp Rectangle.cpp Liste.cpp Point.cpp Forme.cpp tests_catch.cpp Groupe.cpp
SRC_TEST = tests_catch.cpp Forme.cpp
#SRC=$(wildcard *.cpp)  
EXE=testo

CXXFLAGS+=-Wall -Wextra -MMD -g -fdiagnostics-color=auto -O2
LDFLAGS= #-lSDL

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

test:
	g++ -o test tests_catch.cpp Forme.cpp $(CXXFLAGS)

-include $(DEP)