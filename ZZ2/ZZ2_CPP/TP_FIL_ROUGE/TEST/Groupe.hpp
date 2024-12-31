#ifndef GROUPE_HPP_AZ
#define GROUPE_HPP_AZ
#include "Cercle.hpp"
#include "Rectangle.hpp"
#include "Forme.hpp"
#include <iostream>
#include <vector>
const int TAILLE = 10;

class Groupe : public Forme
{
    
public:
    int nb_f;
    int compteur;
    Groupe();
    Groupe(Point, int, int);
    Groupe(int, int, int, int);

    std::vector<Forme> MyForms;
    

    int getCompteur();
    std::string toString() ;

    void add(Forme&);

    void afficher();
};

#endif
