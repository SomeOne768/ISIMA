#include <algorithm>

#include "deviant.hpp"

Personne::Personne() : Personne("inconnu") {}
Personne::Personne(std::string s) : nom(s)
{
    type = TYPE::PERSONNE;
    CITE.add();
}
std::string Personne::getNom() const
{
    return nom;
}

void Personne::setNom(std::string s)
{
    nom = s;
}

int Individu::compteur = 0;

Individu::Individu()
{

    compteur++;
    id = compteur;
}

int Individu::getCompteur()
{
    return compteur;
}

std::ostream &Individu::afficher(std::ostream &oss) const
{
    oss << id;
    return oss;
}

int Individu::getId() const
{
    return id;
}

std::ostream &Personne::afficher(std::ostream &oss) const
{
    oss << nom << " " << id;
    return oss;
}

Individu::~Individu() {}
Personne::~Personne()
{
    CITE.del();
}

TYPE Individu::getType() const
{
    throw IllegalException();
}

TYPE Personne::getType() const
{
    return type;
}

IllegalException::IllegalException() : std::exception() {}
const char *IllegalException::what() throw()
{
    return "illegal exception";
}

int Cite::size() const
{
    return nb;
}

Cite CITE{};

void Cite::add()
{
    nb++;
}
void Cite::del()
{
    nb--;
}

Deviant::Deviant(const Personne &p) : Deviant(p, "")
{

}

Deviant::Deviant(const Personne &p, std::string d) :  date(d)
{
        CITE.del();
        id = p.getId();
        type = TYPE::DEVIANT;
}
Deviant::~Deviant()
{
}
void Deviant::setObs(std::string d)
{
    date = d;
}
std::string Deviant::getObs() const
{
    return date;
}

bool Deviant::operator<(const Deviant &d) const
{
    return date < d.date;
}

TYPE Deviant::getType() const
{
    return type;
}


void Covid::push(Deviant &p)
{
    liste.push(&p);
}

Individu& Covid::top() 
{
    return *liste.top();
}

void Covid::pop()
{
    liste.pop();
}