#include "Reseau.hpp"
#include <algorithm>
#include <exception>

Reseau::Reseau() {}

Reseau::~Reseau() {}

void Reseau::ajouter(std::string num)
{
    liste.push_back(num);
    sort(liste.begin(), liste.end());
    Telephone t{num};
    t.setReseau(this);
    tels.push_back(t);
}

std::string Reseau::lister() const
{
    std::string out = "";
    for (auto &elt : liste)
    {
        out += elt + "\n";
    }

    return out;
}

Telephone &Reseau::trouveTel(std::string num)
{
    for (auto &elt : tels)
    {
        if (elt.getNumero() == num)
        {
            return elt;
        }
    }

    throw MauvaisNumero();
}

void Reseau::envoyerSMS(SMS &s)
{
    // On cherche l'expediteur
    for(auto &elt : tels)
    {
        if(elt.getNumero() == s.expediteur || elt.getNumero() == s.destinataire)
        {
            elt.incMessage();
        }
    }
}


void Reseau::envoyerMMS(MMS *s)
{
    for(auto &elt : tels)
    {
        if(elt.getNumero() == s->expediteur || elt.getNumero() == s->destinataire)
        {
            elt.incMessage();
        }
    }
}