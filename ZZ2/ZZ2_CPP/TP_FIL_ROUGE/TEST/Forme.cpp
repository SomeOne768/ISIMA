#include "Forme.hpp"
// #include "Point.hpp"

int Forme::nbFormes = 0;

Forme::Forme() : Forme(0, 0)
{
}

Forme::Forme(int x, int y) : Forme(Point(x, y), COULEURS::BLEU)
{
}

Forme::Forme(Point p, COULEURS c) 
{
    id = nbFormes;
    nbFormes++;
    this->p = p;
    couleur = c;
    w = h = 0;
}

Forme::Forme(int x, int y, int w, int h, COULEURS c)
{
    id = nbFormes;
    nbFormes++;
    Point p{x,y};
    this->p = p;
    couleur = c;
    this->w = w;
    this->h = h;
}

Forme::~Forme()
{
}

int Forme::getCompteur()
{
    return nbFormes;
}

void Forme::afficher()
{
    printf("w:%d h:%d\n", w, h);
}

std::string Forme::toString()
{
    char buffer[100];
    sprintf(buffer, "Forme: %d %d", p.getX(), p.getY());

    std::string s(buffer);
    return s;
}

COULEURS Forme::getCouleur()
{
    return couleur;
}

void Forme::setCouleur(COULEURS c)
{
    couleur = c;
}

Point &Forme::getPoint()
{
    return p;
}

void Forme::setX(int x)
{
    p.setX(x);
}

void Forme::setY(int y)
{
    p.setY(y);
}

int Forme::prochainId()
{
    return nbFormes;
}

int Forme::getId()
{
    return id;
}

int Forme::getHauteur()
{
    return h;
}

void Forme::setHauteur(int l)
{
    h = l;
}

int Forme::getLargeur()
{
    return w;
}

void Forme::setLargeur(int L)
{
    w = L;
}

Forme* Forme::clone(const Forme& f) const
{
    Forme *out = new Forme(f.p.getX(), f.p.getY());

    return out;
}