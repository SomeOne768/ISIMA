#include <iostream>

// int main()
// {

// int a = 5;
// int &r = a;

// r = 58;

// std::cout << a;

// return 0;
// }

void fonction1(int &a)
{
    std::cout << &a << std::endl;
}

void fonction1(int *a)
{
    std::cout << &a << std::endl;
}

//Écrire une fonction qui permet l'échange de deux variables de type int
// avec des pointeurs
// avec des références

void exchangeValue(int *a, int *b)
{
    int c = (*a);
    *a = *b;
    *b = c;
}

void exchangeValue(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

int main(int, char **)
{
    int age = 45;

    std::cout << &age << std::endl;
    fonction1(age);
    fonction1(&age);

    int a = 3;
    int b = a;
    int &c = a;

    std::cout << a << " " << b << " " << c << std::endl;
    b = 4;
    std::cout << a << " " << b << " " << c << std::endl;
    c = 5;
    std::cout << a << " " << b << " " << c << std::endl;
    a = 6;
    std::cout << a << " " << b << " " << c << std::endl;

    std::cout << "Valeur: a-" << a << " b-" << b << "\n";
    exchangeValue(&a, &b);
    std::cout << "\nEchange par pointeurs: a-" << a << " b-" << b << "\n";
    exchangeValue(a,b);
    std::cout << "\nEchange par reference: a-" << a << " b-" << b << std::endl;

    return 0;
}
