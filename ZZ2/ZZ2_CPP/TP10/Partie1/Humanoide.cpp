#include <iostream>
#include "Humanoide.hpp"

Humanoide::Humanoide(std::string nom, std::string type, SEXE sexe, int age)
: Humain(nom, sexe, age), Machine(type, 0, 3)
{
}


std::string Humanoide::getNom()
{
    return nom;
}
std::string Humanoide::getType()
{
    return Machine::nom;
}

SEXE Humanoide::getGenre()
{
    return sexe;
}

int Humanoide::getAge()
{
    return age;
}

int Humanoide::getIfixit()
{
    return ifixit;
}