#ifndef RECTANGLE_HPP_AZ
#define RECTANGLE_HPP_AZ
#include "Forme.hpp"
class Rectangle : public Forme
{

public:
    Rectangle();
    Rectangle(int, int, int, int);
    std::string toString() override;
    void afficher() override;
    virtual Forme *clone(const Rectangle &) const;

};

#endif