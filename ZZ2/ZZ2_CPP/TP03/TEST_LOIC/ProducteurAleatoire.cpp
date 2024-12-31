#include <iostream>
#include <fstream>
#include "ProducteurAleatoire.hpp"
#include <random>




void ProducteurAleatoire::produire(int quantite, std::string filename){
    std::ofstream fichier{filename.c_str()};

    if(!fichier.fail())
    {
        fichier << quantite << '\n';
        for (int i = 0; i < quantite; ++i)
            fichier << rand()%100+1 << std::endl;

        fichier.close();
    }
    this->travail++;

}
