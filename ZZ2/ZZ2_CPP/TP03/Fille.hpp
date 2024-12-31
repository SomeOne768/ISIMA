#ifndef FILLE_HPP_AZ
#define FILLE_HPP_AZ
#include "Mere.hpp"

class Fille : public Mere{
    std::string name;

public:
    Fille();
    Fille(std::string nom);
    ~Fille();
    virtual void afficher() override;
};


#endif