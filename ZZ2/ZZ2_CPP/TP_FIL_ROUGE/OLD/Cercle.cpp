#include <iostream>
#include "Cercle.hpp"

Cercle::Cercle() : Cercle(0, 0, 0, 0) {}
Cercle::Cercle(int x, int y, int w, int h) : Forme(w, h), x(x), y(y)
{
}

Cercle::Cercle(int cx, int cy, int rayon) : Cercle(cx - rayon, cy - rayon, rayon, rayon)
{
}

std::string Cercle::toString()
{
    char buffer[100];
    sprintf(buffer, "CERCLE: %d %d %d %d", x, y, w, h);
    std::string s = buffer;
    return s;
}

void Cercle::afficher()
{
    printf("Cercle - w:%d h:%d x:%d y:%d\n", w, h, x, y);
}
