#include <iostream>
#include "Famille.hpp"



Famille::Famille(int taille){
    if(taille<0)
    {
        fprintf(stderr, "Problème valeur\n");
        exit(-1);
    }
    // this->tab = new Bavarde[taille];
    this->tab = (Bavarde*)malloc(sizeof(Bavarde));
}