#include "Forme.hpp"

int Forme::nbFormes = 0;

Forme::Forme(): Forme(0, 0){
}

Forme::Forme(int w, int h){
    nbFormes++;
    this->w = w;
    this->h = h;
}

int Forme::getCompteur()
{
    return nbFormes;
}

void Forme::afficher(){
    printf("w:%d h:%d\n", w, h);
}

std::string Forme::toString(){
    char buffer[100];
    sprintf(buffer, "Forme: %d %d", w, h);

    std::string s(buffer);
    return s;
}