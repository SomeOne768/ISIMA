#ifndef HUMANOIDE__HPP_AZ
#define HUMANOIDE__HPP_AZ
#include "Machine.hpp"
#include "Humain.hpp"

class Humanoide : public Humain, public Machine
{
    using Humain::nom;

public:
    Humanoide(std::string nom, std::string type, SEXE, int);
    std::string getNom();
    std::string getType();
    SEXE getGenre();
    int getAge();
    int getIfixit();
};

#endif