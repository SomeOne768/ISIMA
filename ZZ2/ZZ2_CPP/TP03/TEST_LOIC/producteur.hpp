#ifndef __CPP3_PRODUCTEUR_HPP__
#define __CPP3_PRODUCTEUR_HPP__

#include <iostream>


class Producteur {
protected:
    int travail = 0;
    

public:

    int getTravail();
    virtual void produire(int, std::string);
    

};

#endif
