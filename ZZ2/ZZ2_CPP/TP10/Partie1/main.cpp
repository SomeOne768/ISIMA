#include <iostream>


// Exercice 1
// class Mere
// {
// public:
//     Mere() 
//     {
//         // cout << "Mere::Mere()" << endl;
//         tab = new int[100];
//     }
//     virtual ~Mere()
//     {
//         // cout << "Mere::~Mere()" << endl;
//         delete[] tab;
//     }

// protected:
//     int *tab;
// };

// class Fille : public Mere
// {
// public:
//     Fille() 
//     {
//         // cout << "Fille:Fille()" << endl;
//         tab = new double[100];
//         // Mere::tab[50] = 4;
//     }
//     virtual ~Fille()
//     {
//         // cout << "Fille::~Fille()" << endl;
//         delete[] tab;
        
//     }

// protected:
//     double *tab;
// };



//Exercice 2
// class Mere {
//  public:
//   Mere() { m(); }
//   virtual void m() { std::cout << "mm" << std::endl; }
//   virtual ~Mere() {}
// };

// class Fille : public Mere {
//  public:
//   Fille() { m(); }
//   virtual void m() { std::cout << "mf" << std::endl; }
//   virtual ~Fille() {}
// };


int main(int, char **)
{
    // Exercice 1
    // Mere *m = new Fille();

    // std::cout << "penser a valgrind" << std::endl;
    // delete m;

    //Exercice 2
    
    // Fille *f = new Fille{};

    return 0;
}
