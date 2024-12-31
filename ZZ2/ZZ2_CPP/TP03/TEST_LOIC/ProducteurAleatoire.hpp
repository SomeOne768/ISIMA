#ifndef __CPP3_PRODUCTEURALEATOIRE_HPP__
#define __CPP3_PRODUCTEURALEATOIRE_HPP__

#include <iostream>
#include "producteur.hpp"

class ProducteurAleatoire : public Producteur{


public:
    virtual void produire(int, std::string);
};


#endif