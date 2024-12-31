#include <iostream>
#include <fstream>

int main(int, char **)
{

    // Ecriture dans un fichier
    std::string nom = "mon_fichier.txt";
    std::ofstream fichier(nom.c_str());

    int quantite = 10;
    if (!fichier.fail())
    {
        fichier << quantite << std::endl;
        for (int i = 0; i < quantite; ++i)
            fichier << i + 1 << std::endl;

        fichier.close();
    }

    // LEcture fichier

    std::ifstream fichierEcriture; // autre manière d'ouvrir un fichier
    int i = 0, max;

    fichierEcriture.open(nom.c_str());
    if(fichierEcriture.fail())
        exit(-1);
    
    fichierEcriture >> max;
    
    while (!fichierEcriture.eof() && i < max)
    {
        double lecture;
        fichierEcriture >> lecture;
        i++;
        std::cout << lecture << " ";
    }
    std::cout << '\n';

    fichierEcriture.close();

    return 0;
}
