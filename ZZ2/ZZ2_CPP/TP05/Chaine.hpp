#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <iostream>
#include <fstream>

class Chaine  {
    int capacity;
    int size;
    char *tab;
    

public:
int iterator = 0;
    Chaine();
    Chaine(char *);
    Chaine(const char *);
    Chaine(int);
    Chaine(const Chaine&);
    ~Chaine();
    char* c_str() const;
    int getCapacite() const;
    int getSize() const;

    Chaine operator=(char *);
    Chaine operator=(Chaine&);

    void afficher() const;
    void afficher(std::ostream&) const;

    Chaine& operator<<(const Chaine c);
    bool operator==(const char*) const;

    char& operator[](int);

    const char& operator[](int) const;
};

#endif
