#include <iostream>
#include "Point.hpp"



int main()
{

    Point p;

    std::cout << p.getX() << std::endl;
    p.setX(5);
    std::cout << p.getX() << std::endl;
    p.deplacerVers(0,0);
    printf("(%d, %d)\n", p.getX(), p.getY());
    p.deplacerDe(5,67);
    printf("(%d, %d)\n", p.getX(), p.getY());

    Point *p1 = new Point();
    Point *p2 = new Point(0, 0);

    Point p3(0,0);
    Point p4{};
    Point p5{0,0};

    printf("Compteur:%d\n", Point::getCompteur());
    printf("Compteur:%d\n", p.getCompteur());
    printf("Compteur:%d\n", p1->getCompteur());
    printf("Compteur:%d\n", p3.getCompteur());
    printf("Compteur:%d\n", p4.getCompteur());
    

    return 0;
}