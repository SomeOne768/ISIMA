#include "Humain.hpp"

Humain::Humain(std::string nom, SEXE s, int age) : nom(nom), sexe(s), age(age) {}

std::string Humain::getNom() const
{
    return nom;
}

SEXE Humain::getGenre() const
{
    return sexe;
}

int Humain::getAge() const
{
    return age;
}

void Humain::setNom(std::string newname)
{
    nom = newname;
}

void Humain::setAge(int newage)
{
    age = newage;
}

void Humain::setGenre(SEXE newsexe)
{
    sexe = newsexe;
}