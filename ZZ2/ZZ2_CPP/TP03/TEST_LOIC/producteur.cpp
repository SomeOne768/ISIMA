#include "producteur.hpp"
#include <fstream>

/*
bool Producteur::produire(int quantite, std::string nom) {
}
*/

int Producteur::getTravail(){
    return travail;
}

void Producteur::produire(int quantite, std::string filename){
    std::ofstream fichier{filename.c_str()};

    if(!fichier.fail())
    {
        fichier << quantite << '\n';
        for (int i = 0; i < quantite; ++i)
            fichier << i+1 << std::endl;

        fichier.close();
    }
    this->travail++;
}