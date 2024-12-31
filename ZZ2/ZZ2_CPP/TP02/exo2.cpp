#include <iostream>

// #include "Bavarde.hpp"
class Bavarde
{
private:
    int x;
public:
    Bavarde(/* args */);
    Bavarde(int);
    Bavarde(Bavarde&);
    ~Bavarde();
    int getX();    
    // Bavarde& operator=(const Bavarde &b);

} bizarre(1);

Bavarde::Bavarde(){
    printf("Construction de 0\n");
    x = 0;
}

Bavarde::Bavarde(int x){
    printf("Construction de %d\n", x);
    this->x = x;
}

Bavarde::~Bavarde(){
    printf("Tais-toi %d!\n", this->x);
}


Bavarde globale(2);


void fonction(Bavarde b){
    (void)b;
    std::cout << "code de la fonction";
}

int Bavarde::getX(){
    return x;
}

Bavarde::Bavarde(Bavarde &b) : Bavarde(b.x){
    
}


// Bavarde& Bavarde::operator=(const Bavarde &b)
// {   
//     *this = b;
//     return *this;
// }




int main(){

    Bavarde b1(3);
    Bavarde b2(4);
    // Bavarde *p = new Bavarde(5);

    

    std::cout << Bavarde(0).getX() << std::endl;

    std::cout << "ok\n";
    Bavarde b4 = b1;
    std::cout << "copie ?: " << ((&b4 != &b1) ? "True" : "False") << ((&b4 != &b1) ? " " : " pas") << "ok\n";
    



    return 0;
}