#ifndef __LISTE_HPP__AZ
#define __LISTE_HPP__AZ
#include "Cercle.hpp"
#include "Rectangle.hpp"
#include "Forme.hpp"

#include <iostream>

const int TAILLE = 10;

class Liste
{
public:
    int nb_c;
    int nb_r;
    int compteur;
    Liste();

    Rectangle rectangles[TAILLE];
    Cercle cercles[TAILLE];
    //DEMANDER PROF: Cercle *cercles = new Cercle[TAILLE];

    int getCompteur();
    std::string toString();
    void add(Rectangle&);
    void add(Cercle&);
    void afficher();

    //DEMANDER prof: static void afficherTab(Forme **tab, int n);
    static void afficherTab(Forme tab[TAILLE], int n);
    // static void afficherTab(Rectangle tab[TAILLE], int n);
    // static void afficherTab(Cercle tab[TAILLE], int n);
};

#endif