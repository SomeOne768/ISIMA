#ifndef A_HPP_AZ
#define A_HPP_AZ
// #include "B.hpp"

class B;
class A
{
    // int i;

public:
    int i;
    void exec(int);
    void send(B *b);
};

#endif