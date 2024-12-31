#ifndef PILE_HPP_AZ
#define PILE_HPP_AZ
#include <exception>


class Pile
{

    int taille;
    int n = 0;
    int *tab = nullptr;

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
    Pile();
    Pile(int);
    ~Pile();

    bool empty();
    bool push(int);
    int pop();
    int top();
    int size()
    {
        return n;
    }
};

#endif