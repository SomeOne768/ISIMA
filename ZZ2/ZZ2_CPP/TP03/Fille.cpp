#include <iostream>
#include "Fille.hpp"


Fille::Fille(): Mere(){
    printf("J'instancie une Fille\n");
}
Fille::Fille(std::string nom): Mere(nom){
}


Fille::~Fille(){
    printf("Je détruits une Fille\n");
}

void Fille::afficher(){
    printf("Fille\n");
}