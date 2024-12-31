#ifndef TELEPHONE_HPP_AZ
#define TELEPHONE_HPP_AZ
#include <iostream>
#include "MMS.hpp"

class Reseau;
class Telephone
{
    std::string num;
    Reseau *r;
    int nbMessages = 0;

public:
    Telephone();
    Telephone(std::string);
    ~Telephone();

    std::string getNumero() const;
    void setNumero(std::string);
    Reseau *getReseau() const;
    void setReseau(Reseau *);
    int getNbMessages() const;
    void textoter(std::string, std::string);
    void incMessage()
    {
        nbMessages++;
    }

    void mmser(std::string, MMS*);
};

class MauvaisNumero : public std::invalid_argument
{
public:
    MauvaisNumero(std::string s) : std::invalid_argument(s) {}
    MauvaisNumero() : std::invalid_argument("mauvais numero") {}
};

#endif