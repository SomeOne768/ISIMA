#ifndef HERITAGE_CPP_AZ
#define HERITAGE_CPP_AZ
#include <iostream>

class Humain : public Individu
{

public:
    // Le constructeur permet de donner un nom, les autres caractéristiques sont par défaut :
    // pas trop intelligent, ni fort, ni rapide, ni trop sensible à la magie
    Humain(std::string name) : Individu() 
    {
        this->name = name;
        IQ = 50;
        strength = 50;
        speed = 50;
        mana = 10;
    }
};

// Proposer une classe Elfe où les caractéristiques par défaut sont bien plus élevées que les Humains
class Elf : public Individu
{
public:
    Elf(std::string name) : Individu() 
    {
        this->name = name;
        IQ = 100;
        strength = 100;
        speed = 100;
        mana = 100;
    }
};


class Orc : public Individu
{
public:
    Orc(std::string name) : Individu() 
    {
        this->name = name;
        IQ = -15;
        strength = 1000;
        speed = 20;
        mana = 0;
    }
};

// Proposer une classe Sorcier abstraite dont la seule méthode sera ensorceler()
class Sorcier
{
public:
    virtual void ensorceler() = 0;
};

// Proposer une classe Soldat abstraite dont la seule méthode sera combattre()
class Soldat
{

public:
    virtual void combattre() = 0;
};

// Écrire une classe Mage des humains pratiquant la magie. Un humain a besoin de parler pour faire de la magie.
class Mage : public Humain, public Sorcier
{

public:
    Mage(std::string name) : Humain(name), Sorcier() {}
    void ensorceler()
    {
        std::cout << "Je parle !" << "\n";
    }
};

// Écrire une classe Chaman des elfes pratiquant la magie (enfin, plus que la moyenne, et de loin). Les chamans ne parlent pas pour faire de la magie !
class Chaman : public Elf, public Sorcier
{

public:
    Chaman(std::string name) : Elf(name) 
    {
        mana =  500;
    }

    void ensorceler(){};
};

// Proposer un conteneur pour référencer tous les sorciers quelle que soit leur espèce
// Tous les sorciers sont des individus en plus d'être sorcier

// Pas sur de comprendre la Q
class Conteneur : public Individu, public Sorcier
{
public:
    // Je contiens
    Conteneur(Individu *individu) : Individu(*individu) {};
    void ensorceler()
    {
        std::cout << "Je ne suis qu'un conteneur\n";
    }
};

// Vérifier qu'un parcours des éléments est possible en appelant la méthode ensorceler() de chaque élément.

#endif