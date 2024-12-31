#ifndef CERCLE_HPP_AZ
#define CERCLE_HPP_AZ
#include "Forme.hpp"

class Cercle : public Forme
{

protected:
    int x;
    int y;

public:
    Cercle();
    Cercle(int, int, int, int);
    Cercle(int cx, int cy, int rayon);
    std::string toString() override;
    void afficher() override;
    int ordre;
};

#endif