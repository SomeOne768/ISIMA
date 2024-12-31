#include <iostream>
#include <string>
#include <cstring>
int main(int, char **)
{                           // parametres muets
    std::string str1, str2; // type chaines de caracteres"

    std::cout << "Saisir !\n";
    std::cin >> str1;
    std::cout << "Saisir !\n";
    std::cin >> str2;
    std::cout << "Vous avez saisie:\n1 - " << str1 << ":" << str1.length() << "\n2 - " << str2 << ": "<< str2.size();
    std::cout << "\nlongueur" << std::strlen(str1.c_str()) << std::endl;

    //length: taille de la chaine et size taille du tableau

    //afficher la plus petite des deux (ordre lexicographique

    if(str1<str2)
    {
        std::cout << "Plus petite: " << str1 << "\n";
    }
    else{
        std::cout << "Plus petite: " << str2 << std::endl;
    }

    return 0;
}
