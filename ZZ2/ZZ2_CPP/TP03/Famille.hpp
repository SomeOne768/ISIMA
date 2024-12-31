#ifndef FAMILLE_HPP_AZ
#define FAMILLE_HPP_AZ
#include "Bavarde.hpp"
#include <cstdio>
#include <stdlib.h>
class Famille{
    Bavarde *tab;

public:
    Famille(int taille);
    ~Famille(){
        printf("Destruction de la famille\n");
        // delete [] tab;
        free(tab);
    }


};



#endif