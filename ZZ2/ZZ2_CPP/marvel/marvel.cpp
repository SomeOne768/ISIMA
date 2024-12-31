#include "marvel.hpp"
#include <sstream>

Personne Personne::INCONNU = Personne("Inconnu", "Inconnu", Personne::INDETERMINE);
Personne::Personne(std::string p, std::string n) : Personne::Personne(p, n, Personne::INDETERMINE) {}

Personne::Personne(std::string p, std::string n, Genre g) : prenom(p), nom(n), genre(g)
{
}

std::string Personne::getPrenom() const
{
    return prenom;
}

std::string Personne::getNom() const
{
    return nom;
}

Personne::Genre Personne::getGenre() const
{
    return genre;
}

void Personne::afficher(std::stringstream &oss) const
{
    std::string out = prenom + " " + nom;
    switch (genre)
    {
    case Personne::Genre::FEMME:
        out += " [FEMME]";
        break;

    case Personne::Genre::HOMME:
        out += " [HOMME]";
        break;

    case Personne::Genre::INDETERMINE:
        out += " [INDETERMINE]";
        break;

    default:
        break;
    }
    oss << out;
}

bool Personne::operator==(const Personne &p) const
{

    return p.genre == genre && p.nom == nom && p.prenom == prenom;
}

Super::Super(std::string n) : Super(n, Personne::INCONNU) {}
Super::Super(std::string n, Personne p) : nom_scene(n), p(p)
{
}

std::string Super::getNom() const
{
    return nom_scene;
}
bool Super::estAnonyme() const
{
    // return p == Personne::INCONNU;
    return ano;
}

void Super::enregistrer()
{
    ano = false;
}

Personne Super::getIdentite() const
{
    if (ano)
        throw AnonymeException();
    return p;
}

void Super::setIdentite(Personne p)
{
    this->p = p;
    ano = true;
}

Capacite::Capacite(std::string nom, int niv) : nom(nom), niveau(niv) {}

Materiel::Materiel(std::string nom, int niv) : Capacite(nom, niv) {}

void Materiel::actionner(std::ostream &oss) const
{
    oss << nom << " [" << niveau << "] en action";
}

Physique::Physique(std::string n, int niv) : Capacite(n, niv)
{
}
void Physique::exercer(std::ostream &oss) const
{
    oss << nom << " [" << niveau << "]";
}

Psychique::Psychique(std::string n, int niv) : Capacite(n, niv) {}
void Psychique::penser(std::ostream &oss) const
{
    oss << nom << " [" << niveau << "]";
}

void Materiel::utiliser(std::ostream &oss) const
{
    actionner(oss);
}

void Physique::utiliser(std::ostream &oss) const
{
    exercer(oss);
}

void Psychique::utiliser(std::ostream &oss) const
{
    penser(oss);
}
Capacite::~Capacite() {}
Materiel::~Materiel() {}
Psychique::~Psychique() {}
Physique::~Physique() {}
int Capacite::getNiveau() const
{
    return niveau;
}

void Super::ajouter(Capacite *c)
{
    capas.push_back(c);
}

int Super::getNiveau() const
{
    int score = 0;
    for (Capacite *c : capas)
    {
        score += c->getNiveau();
    }

    return score;
}

std::string Capacite::getNom() const
{
    return nom;
}

Physique *Physique::clone() const
{
    Physique *c = new Physique{nom, niveau};
    return c;
}

Materiel *Materiel::clone() const
{
    Materiel *c = new Materiel{nom, niveau};
    return c;
}

Psychique *Psychique::clone() const
{
    Psychique *c = new Psychique{nom, niveau};
    return c;
}

void Super::setNom(std::string s)
{
    nom_scene = s;
}

Equipe::Equipe(std::string n) : nom(n) {}

int Equipe::getNombre() const
{
    return nb;
}
void Equipe::ajouter(Super *s)
{
    if (s)
    {
        supers.push_back(s);
        nb++;
        niv += s->getNiveau();
    }
}

int Equipe::getNiveau() const{
    return niv;
}