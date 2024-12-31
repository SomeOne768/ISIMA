#ifndef FORME_HPP_AZ
#define FORME_HPP_AZ
#include <iostream>

class Forme
{
    static int nbFormes;

protected:
    int w;
    int h;

public:
    Forme();
    Forme(int, int);
    static int getCompteur();
    virtual std::string toString();
    virtual void afficher();
};

#endif