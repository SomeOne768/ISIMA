#include <iostream>
#include "Cercle.hpp"
#include <sstream>

Cercle::Cercle() : Cercle(0, 0, 0, 0) {}
Cercle::Cercle(int x, int y, int w, int h)
    : Forme(x, y)
{
    this->w = w;
    this->h = h;
}

Cercle::Cercle(int cx, int cy, int rayon) : 
    Cercle(cx - rayon, cy - rayon, rayon, rayon)
{
}

std::string Cercle::toString()
{
    std::ostringstream oss;
    oss << "CERCLE: "<< this->getPoint().getX() <<" "<< this->getPoint().getY() << " " << w << " " << h;
    std::string s(oss.str());
    return s;
}

void Cercle::afficher()
{
    printf("Cercle - w:%d h:%d x:%d y:%d", w, h, this->getPoint().getX(), this->getPoint().getY());
}

int Cercle::getRayon()
{
    return w;
}

void Cercle::setRayon(int r)
{
    // On retouche au centre  ?
    w = h = r;
}

Forme* Cercle::clone(const Cercle &c) const
{
    Cercle *out = new Cercle(c.getX(), c.getY(), c.w, c.h);

    return out;
}