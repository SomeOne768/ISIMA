#ifndef marvel__hpp
#define marvel__hpp
#include <iostream>
#include <sstream>
#include <vector>

class Personne
{

public:
    enum Genre
    {
        HOMME,
        FEMME,
        INDETERMINE
    };
    Personne(std::string, std::string);
    Personne(std::string, std::string, Genre);
    std::string getPrenom() const;
    std::string getNom() const;
    Genre getGenre() const;
    void afficher(std::stringstream &) const;

    static Personne INCONNU;
    // Genre INDETERMINE

    bool operator==(const Personne &) const;

private:
    std::string prenom,
        nom;

    Genre genre;
};

class Capacite;
class Super
{
    std::string nom_scene;
    Personne p;
    bool ano = true;
    std::vector<Capacite *> capas;

public:
    Super(std::string);
    Super(std::string, Personne);
    std::string getNom() const;
    bool estAnonyme() const;

    void enregistrer();
    Personne getIdentite() const;
    void setIdentite(Personne p);
    void ajouter(Capacite *);
    int getNiveau() const;
    void setNom(std::string);
};

class AnonymeException : public std::exception
{
public:
    AnonymeException() : std::exception() {}
    virtual const char *what() const noexcept override
    {
        return "identite anonyme";
    }
};

// Lorsqu'une capacité est utilisée, on fait une écriture dans un flux de sortie (log).
// [Materiel] [Psychique] [Capacite]
// Chacune des capacités spécialisées a une méthode particulière appelée par la méthode polymorphique utiliser(). Plus le niveau d'une capacité est important, plus elle est impressionnante.
// Wolverine, Deadpool et Captain America ont la capacité de régénération mais elle est beaucoup plus impressionnante (rapide) chez Wolferine et Deadpool.
// [Capacite1]

class Capacite
{
protected:
    std::string nom;
    int niveau;

public:
    Capacite(std::string, int);
    virtual ~Capacite();
    virtual void utiliser(std::ostream &) const = 0;
    int getNiveau() const;
    std::string getNom() const;

    virtual Capacite *clone() const = 0;
};

class Materiel : public Capacite
{
public:
    Materiel(std::string, int);
    ~Materiel();
    virtual void utiliser(std::ostream &) const;
    void actionner(std::ostream &) const;
    virtual Materiel *clone() const;
};

class Physique : public Capacite
{
public:
    Physique(std::string, int);
    ~Physique();
    virtual void utiliser(std::ostream &) const;
    void exercer(std::ostream &) const;
    virtual Physique *clone() const;
};

class Psychique : public Capacite
{
public:
    Psychique(std::string, int);
    ~Psychique();
    virtual void utiliser(std::ostream &) const;
    void penser(std::ostream &) const;
    virtual Psychique *clone() const;
};

class Equipe
{
    std::string nom;
    int nb = 0;
    std::vector<Super *> supers;
    int niv = 0;

public:
    Equipe(std::string);
    int getNombre() const;
    void ajouter(Super *);
    int getNiveau() const;
};

#endif
