#include "Pile.hpp"
#include <iostream>

Pile::Pile(int i)
{
    if (i <= 0)
        throw std::invalid_argument("argument must be >0");

    taille = i;
    tab = new int[taille];
    if(tab == nullptr)
        throw std::bad_alloc();
}

Pile::Pile() : Pile(10) {}

Pile::~Pile()
{
    if (tab)
        delete[] tab;
}

bool Pile::empty()
{
    return n == 0;
}

bool Pile::push(int elt)
{
    if (n == taille)
        return false;

    tab[n] = elt;
    n++;
    return true;
}

int Pile::pop()
{
    if (n < 1)
        throw ArrayEmpty();

    n--;
    return tab[n];
}

int Pile::top()
{
    if (empty())
        throw ArrayEmpty();

    return tab[n - 1];
}
