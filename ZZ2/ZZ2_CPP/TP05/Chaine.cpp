#include "Chaine.hpp"
#include <cstring>
#include <iostream>

Chaine::Chaine()
{
    capacity = -1;
    size = 0;
    tab = nullptr;
}

Chaine::Chaine(char *s)
{
    capacity = strlen(s);
    size = capacity;
    tab = new char[capacity + 1];
    if (tab)
    {
        strcpy(tab, s);
        tab[size] = '\0';
    }
}

Chaine::Chaine(const char *s) : Chaine((char *)s) {}

Chaine::Chaine(int x) : capacity(x), size(0)
{
    tab = new char[x + 1];
    tab[0] = '\0';
}

Chaine::Chaine(const Chaine &c)
{
    capacity = c.getCapacite();
    size = c.getSize();
    tab = new char[capacity + 1];
    strncpy(tab, c.c_str(), size);
    tab[size] = '\0';
}

Chaine::~Chaine()
{
    if (tab)
    {
        delete[] tab;
    }
}

char *Chaine::c_str() const
{

    return tab;
}

int Chaine::getCapacite() const
{
    return capacity;
}

int Chaine::getSize() const
{
    return size;
}

Chaine Chaine::operator=(char *s)
{
    return Chaine(s);
}

Chaine Chaine::operator=(Chaine &c)
{
    if (&c != this)
    {
        this->capacity = c.getCapacite();
        this->size = c.getSize();

        delete[] this->tab;

        this->tab = new char[capacity + 1];
        strncpy(this->tab, c.c_str(), size);
        tab[size] = '\0';
    }
    return *this;
}

void Chaine::afficher() const
{
    printf("%s", tab);
}

void Chaine::afficher(std::ostream &s) const
{
    s << tab;
}

Chaine& Chaine::operator<<(const Chaine c)
{
    if (&c != this)
    {
        int len = c.size + this->size;

        if (!this->tab)
        {
            std::cout << "Vide\n";
            this->tab = new char[len + 1];
            this->capacity = len;
            this->size = 0;
            this->tab[0] = 0;
        }

        if (len > this->capacity)
        {
            std::cout << "taille trop petite\n";
            Chaine temp(len);
            delete[] this->tab;
            this->tab = new char[len + 1];
            strcpy(this->tab, temp.c_str());
        }
        strcat(this->tab, c.tab); // this->capacity-1-this->size);
        size += c.size;
        tab[size] = 0;
    }
    return *this;
}

bool Chaine::operator==(const char *c) const
{
    return !strcmp(tab, c);
}

char& Chaine::operator[](int i)
{
    // if(i<0 || i>size)
    // {
    //     return NULL;
    // }

    return tab[i];
}

const char& Chaine::operator[](int i) const
{
    return tab[i];
}