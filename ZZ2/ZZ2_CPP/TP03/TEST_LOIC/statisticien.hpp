#ifndef __CPP3_STATISTICIEN_HPP__
#define __CPP3_STATISTICIEN_HPP__

#include <iostream>

class Statisticien {
	
    bool calcul = 0;
    int somme;
    float moyenne;
public:
    void acquerir(std::string);
    bool aCalcule();
    int getSum();
    float getAverage();
};

#endif