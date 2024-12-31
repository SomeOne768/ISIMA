#ifndef __deviant_hpp__
#define __deviant_hpp__

#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
// completer la liste suivant vos besoins

enum class TYPE
{
    PERSONNE,
    DEVIANT
};

// Utiliser une des versions de Cite
// #define CITE Cite::getCite()

class Individu
{

    static int compteur;

protected:
    TYPE type;
    int id;

public:
    Individu();
    virtual ~Individu();
    int getId() const;

    static int getCompteur();
    virtual std::ostream &afficher(std::ostream &) const;

    virtual TYPE getType() const;
};

class Personne : public Individu
{
    std::string nom;

public:
    Personne();
    ~Personne();
    Personne(std::string);
    std::string getNom() const;
    void setNom(std::string);

    virtual std::ostream &afficher(std::ostream &) const;
    TYPE getType() const override;
};

class IllegalException : public std::exception
{

public:
    IllegalException();
    const char *what() throw();
};

class Cite
{
    int nb = 0;

public:
    int size() const;
    void add();
    void del();
};

class Deviant : public Individu
{
    std::string date;
public:
    Deviant(const Personne&);
    Deviant(const Personne&, std::string);
    // Deviant(Personne*);
    ~Deviant();
    void setObs(std::string);
    std::string getObs() const;
    bool operator<(const Deviant &d) const;

    // virtual std::ostream &afficher(std::ostream &) const;
    TYPE getType() const override;

};


class MyPredicat
{

public:
    bool operator()(const Deviant *d1, const Deviant *d2) const
    {
        return *d1 < *d2;
    }
};


class Covid
{
    std::priority_queue<Deviant*, std::vector<Deviant*>,  MyPredicat> liste;
public:
    void push(Deviant&);
    Individu& top() ;
    void pop();

};


extern Cite CITE;
#endif
