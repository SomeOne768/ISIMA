#ifndef CERCLE_HPP_AZ
#define CERCLE_HPP_AZ
#include "Forme.hpp"
#include "Point.hpp"

class Cercle : public Forme
{

public:
    Cercle();
    Cercle(int, int, int, int);
    Cercle(int cx, int cy, int rayon);
    std::string toString() override;
    void afficher() override;
    int getRayon();
    void setRayon(int);
    virtual Forme *clone(const Cercle &) const;
};

#endif