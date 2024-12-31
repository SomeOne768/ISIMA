#include <iostream>


template <typename T>
const T& maximum(const T& a,const T& b) {
    return ((a > b) ? a : b);
}


int main()
{
    int a = 8,
        b = 9;

    double c = 4;
    std::cout << "Le max entre 8 et 9 est:" << maximum(a, b) << std::endl;
    try{
        std::cout << "Le max entre 4 et 9 est:" << maximum((double)a,(double) c) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what();
    }

    return 0;
}