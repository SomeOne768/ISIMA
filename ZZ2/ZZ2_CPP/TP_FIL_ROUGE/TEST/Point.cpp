#include "Point.hpp"

Point::Point() : Point(0, 0) {}

Point::Point(int x, int y) : x(x), y(y)
{
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

Point Point::ORIGINE{0,0};