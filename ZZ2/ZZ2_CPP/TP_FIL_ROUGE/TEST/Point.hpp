#ifndef POINT_HPP_AZ
#define POINT_HPP_AZ

class Point
{
    int x;
    int y;
public:
    Point();
    Point(int, int);
    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);
    static Point ORIGINE;
};



#endif