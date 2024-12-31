#include "Telephone.hpp"
#include "SMS.hpp"
#include "Reseau.hpp"

Telephone::Telephone(std::string n) : num(n)
{
}

Telephone::Telephone() {}

Telephone::~Telephone()
{
}

std::string Telephone::getNumero() const
{
    return num;
}

void Telephone::setNumero(std::string n)
{
    num = n;
}

Reseau *Telephone::getReseau() const
{
    return r;
}

void Telephone::setReseau(Reseau *res)
{
    r = res;
}


int Telephone::getNbMessages() const{
    return nbMessages;
}

void Telephone::textoter(std::string num, std::string texte)
{
    SMS s{getNumero(), num, "2023", texte};
    r->envoyerSMS(s);
}

void Telephone::mmser(std::string num, MMS* s)
{
    SMS * d = s;
    s->destinataire = num;
    s->expediteur = getNumero();
    r->envoyerSMS(*d);
}