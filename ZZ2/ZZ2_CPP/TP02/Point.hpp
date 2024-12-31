#ifndef POINT_HPP_AZ
#define POINT_HPP_AZ

class Point
{

    int x;
    int y;
    static int compteur;

public:
    Point();
    Point(int, int);
    int getX();
    void setX(int);
    int getY();
    // void setY();
    void deplacerDe(int, int);
    void deplacerVers(int, int);
    static int getCompteur();


    

};

#endif