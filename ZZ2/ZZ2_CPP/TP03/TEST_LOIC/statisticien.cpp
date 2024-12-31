#include "statisticien.hpp"
#include <fstream>

void Statisticien::acquerir(std::string nom)
{
    // Somme et moyenne
    std::ifstream file;
    file.open(nom.c_str());

    if (!file.fail())
    {
        calcul = 1;

        int somme = 0, nb=0, quantite;
        file >> quantite;
        
        while(!file.eof() && nb<quantite)
        {
            int val;
            file >> val;
            somme += val;
            nb++;
        }
        this->somme = somme;
        this->moyenne = somme/nb;
    }



}

bool Statisticien::aCalcule()
{
    return calcul;
}


int Statisticien::getSum(){
    return this->somme;
}

float Statisticien::getAverage(){
    return this->moyenne;
}