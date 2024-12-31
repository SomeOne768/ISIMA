#include <iostream>
#include "A.hpp"
#include "B.hpp"



int main(int, char**){

    B *pb = new B();
    A *pa = new A();
    
    std::cout << pa->i << " " << pb->j << std::endl;

    pa->send(pb);
    pb->send(pa);

    std::cout << pa->i << " " << pb->j << std::endl;


    return 0;
}