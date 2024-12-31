#include <iostream>

// Écrire une classe simple avec attribut et encapsulation => OK
class Point1
{
    int monAttribut;

public:
    Point1(){};
    int getMonAttribut() const { return monAttribut; }
    void setMonAttribut(int i) { monAttribut = i; }
};
// Instancier et manipuler un objet simple => OK
/*
Point1 point2{};
point2.setMonAttribut(5);
*/

// Instancier et manipuler un objet constant => OK
/*
const Point1 point3{};
point3.getMonAttribut(5);
*/

// Définir et utiliser un membre de classe => OK
class Point4
{
    int monAttribut;
    static int membreDeClasse;
public:
    Point4(){};
    int getMonAttribut() const { return monAttribut; }
    void setMonAttribut(int i) { monAttribut = i; }
};
int Point4::membreDeClasse=0;

// Écrire un héritage simple public => OK
class Point5 : public Point4
{
public:
    Point5(){};
};

// Utiliser le polymorphisme => OK
class Point6
{
public:
    Point6(){};
    void direQQCH()
    {
        std::cout<<"?\n";
    }

    void direQQCH(std::string s)
    {
        std::cout << s;
    }
};
// Utiliser la liste d'initialisation
class Point7
{
    std::string name;
    int i1;
    
public:
    Point7(std::string name, int i) : name(name), i1(i){};
};

// Connaître la règle des 3 => CONSTRUCTEUR + DESTRUCTEUR + COPIE
class Point8
{
    int useless = 5;
public:
    Point8(){};
    ~Point8(){};
    Point8(Point8 &p)
    {
        useless = p.useless;
    };
};

// Utiliser une exception standard
class Point9
{
    int *p = nullptr;
    
public:
    Point9(){};
    int* getP() 
    {
        if(p == nullptr)
            throw std::exception_ptr();
        
        return p;
    }
};

// Manipuler une référence => OK

// Classe abstraite => un méthdoe en = 0 ou alors constructeur en privée / protégé
class Abstraite
{
private:
    // Je vais être abstraite
    Abstraite();

public:
    virtual void jeSeraisAussiAbstraite() = 0;

};

// Connaître std::string, std::ostream, std::stringstream

// différence entre std::string et const char *

// Créer et lancer une exception personnalisée
class MonException: public std::exception
{
public:
    const char * what() const noexcept override
    {
        return "Méthode à définir pour que ça fonctionne";  
    }
};

// Utiliser un conteneur simple de la bibliothèque standard
// le plus simple : std::vector< MonType > v;

// Connaître les concepts derrières la bibliothèque standard (types de conteneurs, iterateurs, foncteurs)
/*
    conteneurs: listes, vecteurs ...
    iterateurs: pointeurs 
    foncteurs: classe ayant une redefinition de l'opérateur () prenant aucun argument. Ayant un seul but
*/

// Surcharge d'opérateur (notamment <<)
class Ope
{
public:
    std::string operator<<(int)
    {
        std::string s{"Je ne fais R et suis utilisé avec un int à ma droite"};
        return s;
    }

    std::string operator<<(std::string s)
    {
        return "Je ne fais R mais j'ajoute: " + s;
    }
};
// Amitié
class QuelquunVeutEtreMonAmiPlease
{

};


class FriendLess
{
    int jaiDesAttribPrivee;
    //Vas-y soyons ami, tu as accès à mes attrib
    friend QuelquunVeutEtreMonAmiPlease;
};

// Héritage multiple 

// enum class (vu en TP)
enum MonEnum
{
    Enum1,
    Enum2,
    JoubliePasLePointVirgule
};

// Définir et utiliser tout type interne à une classe (const, type interne, classe imbriquée)

// Écrire une classe générique => voir tp pile ou liste avec template 

// Concepts plus avancés de la bibliothèque standard comme les algorithmes (copy, transform, itérateurs avancés)

// Héritage multiple virtuel => on s'en balec

int main()
{
    try
    {
        throw MonException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Ope op;
    std::string s1 = op << 5;

    std::cout << s1 << std::endl;

    std::string s2 = op<< "un chaine à ma droite";
    std::cout << s2 << std::endl;

    MonEnum mavar = MonEnum::Enum1;
    
    return 0;
}