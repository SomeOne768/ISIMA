#ifndef RECTANGLE_HPP_AZ
#define RECTANGLE_HPP_AZ
#include "Forme.hpp"
class Rectangle : public Forme
{
protected:
    int x;
    int y;

public:
    Rectangle();
    Rectangle(int, int, int, int);
    std::string toString() override;
    void afficher() override;
    int ordre;

};

#endif