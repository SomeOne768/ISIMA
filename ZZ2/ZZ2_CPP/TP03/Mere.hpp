#ifndef MERE_HPP_AZ
#define MERE_HPP_AZ
#include <iostream>
class Mere
{
protected:
    static int x;
    std::string nom;

public:
    Mere();
    Mere(std::string);
    ~Mere();
    static int getCompteur();
    virtual void afficher();
    std::string getName();
};

#endif