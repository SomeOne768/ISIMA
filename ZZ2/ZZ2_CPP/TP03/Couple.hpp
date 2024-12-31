#ifndef COUPLE_HPP_AZ
#define COUPLE_HPP_AZ
#include "Bavarde.hpp"
#include <cstdio>

class Couple{
    Bavarde *b1;
    Bavarde *b2;

public:
    Couple(){
        b1 = new Bavarde{1};
        b2 = new Bavarde{2};
    }
    Couple(int x, int y){
        b1 = new Bavarde{x};
        b2 = new Bavarde{y};
    }

    ~Couple(){
        printf("Je détruits %d et %d\n", b1->getX(), b2->getX());
        delete b1;
        delete b2;
    }

};


#endif