#include <cstdio>
#include "Bavarde.hpp"

Bavarde::Bavarde(){
    printf("Construction de 0\n");
    x = 0;
}

Bavarde::Bavarde(int x){
    printf("Construction de %d\n", x);
    this->x = x;
}

Bavarde::~Bavarde(){
    printf("Tais-toi %d!\n", this->x);
}

int Bavarde::getX(){
    return x;
}
void Bavarde::afficher(){
    printf("Affichage de %d\n", x);
}