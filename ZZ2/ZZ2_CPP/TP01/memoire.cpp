#include <iostream>

// int main(int, char **)
// {

//     int a = 4;
//     int *p = nullptr;

//     p = &a;
//     printf("%p %d\n", p, *p);
//     std::cout << *p << " " << p;
// }

// int main(int, char **)
// {
//     int *p = new int;

//     *p = 3;
//     std::cout << *p << std::endl;

//     delete p;

//     return 0;
// }

class Exemple
{
public:
    void afficher()
    {
        std::cout << "hello" << std::endl;
    }
};

int main(int, char **)
{
    // const int TAILLE = 500;

    // int *p = new int[TAILLE];

    // for (auto i = 0; i < TAILLE; ++i)
    //     p[i] = i;
    // for (auto i = 0; i < TAILLE; ++i)
    //     std::cout << p[i] << std::endl;

    // // delete p;
    // delete[] p;

    Exemple e;
    e.afficher();

    return 0;
}
