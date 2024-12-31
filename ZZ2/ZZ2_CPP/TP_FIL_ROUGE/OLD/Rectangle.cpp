#include <iostream>
#include "Rectangle.hpp"


Rectangle::Rectangle() : Rectangle(0,0,0,0){
}

Rectangle::Rectangle(int x, int y, int w, int h) : Forme(w,h), x(x), y(y){
}

std::string Rectangle::toString(){
    char buffer[100];  
    sprintf(buffer, "RECTANGLE: %d %d %d %d", x, y, w, h);
    std::string s = buffer;
    return s;
}


void Rectangle::afficher(){
    printf("Rectangle - w:%d h:%d x:%d y:%d\n", w, h, x, y);
}