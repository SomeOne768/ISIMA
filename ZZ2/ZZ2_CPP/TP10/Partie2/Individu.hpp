#ifndef INDIBIDU_HPP_AZ
#define INDIBIDU_HPP_AZ

// Chaque individu a un nom, une intelligence, une force, une vitesse, une vitalité, ... un potentiel de magie.
// La population, telle que l'on la connait, est constituée d'humains, d'elfes et d'orcs.
// Certains individus ont des caractéristiques exceptionnelles et méritent un traitement particulier : les sorciers ou les soldats par exemple.

class Individu
{
protected:
    std::string name;
    int IQ;
    int strength;
    int speed;
    int vitality;
    int mana;

    // Constructeur private, protected => non instantiable sauf heritage/friend
    Individu(){};
};

#endif