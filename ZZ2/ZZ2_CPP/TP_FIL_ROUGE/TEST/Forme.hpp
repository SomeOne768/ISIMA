#ifndef FORME_HPP_AZ
#define FORME_HPP_AZ
#include <iostream>
#include "Point.hpp"
enum class COULEURS
{
    NOIR,
    BLANC,
    ROUGE,
    JAUNE,
    BLEU,
    VERT
};

class Forme
{
    static int nbFormes;
    int id;

protected:
    int w;
    int h;
    Point p;
    COULEURS couleur = COULEURS::BLEU;

public:
    Forme();
    Forme(int, int);
    Forme(Point, COULEURS);
    Forme(int x, int y, int w, int h, COULEURS c);
    virtual ~Forme();
    static int getCompteur();
    virtual std::string toString();
    virtual void afficher();
    COULEURS getCouleur();
    void setCouleur(COULEURS);
    Point &getPoint();
    void setX(int);
    void setY(int);
    int getX() const
    {
        return p.getX();
    }
    int getY() const
    {
        return p.getY();
    }
    int getHauteur();
    void setHauteur(int);
    int getLargeur();
    void setLargeur(int);

    static int prochainId();
    int getId();
    int ordre;
    
    virtual Forme *clone(const Forme &) const;

};

#endif