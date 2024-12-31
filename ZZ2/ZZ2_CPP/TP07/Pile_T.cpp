#include "Pile_T.hpp"
#include <iostream>

// template <typename T>
// Pile_T<T>::Pile_T(T i)
// {
//     if (i <= 0)
//         throw std::invalid_argument("argument must be >0");

//     taille = i;
//     tab = new T[taille];
//     if(tab == nullptr)
//         throw std::bad_alloc();
// }

// template <typename T>
// Pile_T<T>::Pile_T() : Pile_T<T>(10) {}

// template <typename T>
// Pile_T<T>::~Pile_T()
// {
//     if (tab)
//         delete[] tab;
// }

// template <typename T>
// bool Pile_T<T>::empty()
// {
//     return n == 0;
// }

// template <typename T>
// bool Pile_T<T>::push(T elt)
// {
//     if (n == taille)
//         return false;

//     tab[n] = elt;
//     n++;
//     return true;
// }

// template <typename T>
// T Pile_T<T>::pop()
// {
//     if (n < 1)
//         throw ArrayEmpty();

//     n--;
//     return tab[n];
// }

// template <typename T>
// T Pile_T<T>::top()
// {
//     if (empty())
//         throw ArrayEmpty();

//     return tab[n - 1];
// }
