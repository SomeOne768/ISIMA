#ifndef HUMAIN__HPP_AZ
#define HUMAIN__HPP_AZ
#include <iostream>

enum SEXE
{
    HOMME,
    FEMME
};

class Humain 
{
protected:
    std::string nom;
    SEXE sexe;
    int age;

public:
    Humain(std::string, SEXE, int);

    std::string getNom() const;
    SEXE getGenre() const;
    int getAge() const;

    void setNom(std::string);
    void setAge(int);
    void setGenre(SEXE);

};

#endif