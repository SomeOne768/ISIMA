#include <iostream>
#include "Rectangle.hpp"
#include <sstream>


Rectangle::Rectangle() : Rectangle(0,0,0,0){
}

Rectangle::Rectangle(int x, int y, int w, int h) : Forme(x, y, w, h, COULEURS::BLEU){
}

std::string Rectangle::toString() {
    std::ostringstream oss;
    oss << "RECTANGLE: "<< getX() <<" "<< getY() << " " << w << " " << h;
    std::string s(oss.str());
    return s;   
}


void Rectangle::afficher(){
    printf("Rectangle - w:%d h:%d x:%d y:%d", w, h, getX(), getY());
}

Forme * Rectangle::clone(const Rectangle &r) const
{
    Rectangle *out = new Rectangle(r.getX(), r.getY(), r.w, r.h);
    return out;
}