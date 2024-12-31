#include <cstdio>
#include "Point.hpp"

int Point::compteur = 0;

Point::Point(){
    printf("Constructeur sans arguments\n");
    this->x = 0;
    this->y = 0;
    compteur++;
}


Point::Point(int x, int y){
    printf("Constructeur avec arguments\n");
    this->x = x;
    this->y = y;
    compteur++;
}


int Point::getX(){
    return x;
}

void Point::setX(int val){
    x = val;
}


int Point::getY(){
    return y;
}

void Point::deplacerDe(int dx, int dy)
{
    this->x += dx;
    this->y += dy;
}

void Point::deplacerVers(int x, int y)
{
    this->x += x;
    this->y += y;
}


int Point::getCompteur(){
    return compteur;
}
