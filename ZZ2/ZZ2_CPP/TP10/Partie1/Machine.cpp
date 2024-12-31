#include <iostream>
#include "Machine.hpp"


Machine::Machine(std::string nom, int autonomie, int i) : nom(nom), autonomie(autonomie), ifixit(i)
{

}

const std::string Machine::getType() const
{
    return nom;
}
int Machine::getAutonomie() const
{
    return autonomie;
}

int Machine::getIfixit() const
{
    return ifixit;
}