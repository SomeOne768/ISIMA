#ifndef PILE_T_HPP_AZ
#define PILE_T_HPP_AZ
#include <exception>
#include <iostream>

template <typename T> 
class Pile_T
{

    int taille;
    int n = 0;
    T *tab = nullptr;

public:
    class ArrayFull : public std::exception
    {
        virtual const char * what(){
            return "Array is full";
        }
    };

    class ArrayEmpty : public std::exception
    {
        const char * what() const noexcept override{
            return "Array is empty";
        }
    };
    Pile_T();
    Pile_T(T);
    ~Pile_T();

    bool empty();
    bool push(T);
    T pop();
    T top();
    T size()
    {
        return n;
    }
};


template <typename T>
Pile_T<T>::Pile_T(T i)
{
    if (i <= 0)
        throw std::invalid_argument("argument must be >0");

    taille = i;
    tab = new T[taille];
    if(tab == nullptr)
        throw std::bad_alloc();
}

template <typename T>
Pile_T<T>::Pile_T() : Pile_T<T>(10) {}

template <typename T>
Pile_T<T>::~Pile_T()
{
    if (tab)
        delete[] tab;
}

template <typename T>
bool Pile_T<T>::empty()
{
    return n == 0;
}

template <typename T>
bool Pile_T<T>::push(T elt)
{
    if (n == taille)
        return false;

    tab[n] = elt;
    n++;
    return true;
}

template <typename T>
T Pile_T<T>::pop()
{
    if (n < 1)
        throw ArrayEmpty();

    n--;
    return tab[n];
}

template <typename T>
T Pile_T<T>::top()
{
    if (empty())
        throw ArrayEmpty();

    return tab[n - 1];
}

#endif