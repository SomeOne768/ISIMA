#include <iostream>
#include "Mere.hpp"

int Mere::x = 0;

Mere::Mere(){
    printf("Je m'instancie\n");
    x++;
}

Mere::Mere(std::string nom): Mere(){
    this->nom = nom;
}



Mere::~Mere(){
    printf("Je me détruits\n");
}

int Mere::getCompteur(){
    return x;
}

void Mere::afficher(){
    printf("Mere\n");
}

std::string Mere::getName(){
    return this->nom;
}