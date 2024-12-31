#include <iostream>
#include "Groupe.hpp"

Groupe::Groupe() : Groupe(0, 0, 0, 0)
{
}

Groupe::Groupe(Point p, int w, int h) : Forme(p, COULEURS::BLEU)
{
    this->w = w;
    this->h = h;
    compteur = 0;
    nb_f = 0;
}

Groupe::Groupe(int x, int y, int w, int h) : Forme(x, y)
{
    this->w = w;
    this->h = h;
    compteur = 0;
    nb_f = 0;
}

int Groupe::getCompteur()
{
    return compteur;
}

std::string Groupe::toString() 
{
    std::string out = "";
    for(auto &e: MyForms)
    {
        out += e.toString();
    }

    return out;
}

void Groupe::afficher()
{
    for(auto &e: MyForms)
    {
        std::cout << " " << e.toString();
    }
}



void Groupe::add(Forme &forme) 
{
    nb_f++;
    compteur++;
    MyForms.push_back(forme);
}


// Le type est automatiquement detecté par la lambda car passé par référence.
// Dans notre cas actuel il faudrait en plus donné le tableau donc detecter le nullptr
/*
auto addForme = [](auto &maForme, int &nb)
{
};
*/

// void Groupe::add(Rectangle &r)
// {
//     // add(r, nb_r);
//     // addEncore(r, nb_r);

//     // On souhaite ici mettre à jour les valeur h et w pour contenir toutes les formes
//     if (nb_r < TAILLE)
//     {
//         r.ordre = compteur;
//         this->rectangles[nb_r] = r;
//         nb_r++;
//         compteur++;

//         // On verifie les bords gauche/sup
//         Point p = this->getPoint();
//         if (r.getPoint().getX() < p.getX())
//         {
//             p.setX(r.getPoint().getX());
//         }

//         if (r.getPoint().getY() < p.getY())
//         {
//             p.setY(r.getPoint().getY());
//         }

//         // On verifie les dim:
//         int x_max = r.getPoint().getX() + r.getLargeur();
//         int y_max = r.getPoint().getY() + r.getHauteur();
//         int delta_x = p.getX() + getLargeur() - x_max;
//         int delta_y = p.getY() + getHauteur() - y_max;
//         if (delta_x < 0)
//         {
//             w += delta_x;
//         }

//         if (delta_y < 0)
//         {
//             h += delta_y;
//         }
//     }
// }

// void Groupe::add(Cercle &c)
// {
//     if (nb_c < TAILLE)
//     {
//         c.ordre = compteur;
//         this->cercles[nb_c] = c;
//         nb_c++;
//         compteur++;
//
//         // On verifie les bords gauche/sup
//         Point p = this->getPoint();
//         if (c.getPoint().getX() < p.getX())
//         {
//             p.setX(c.getPoint().getX());
//         }
//
//         if (c.getPoint().getY() < p.getY())
//         {
//             p.setY(c.getPoint().getY());
//         }
//
//         // On verifie les dim:
//         int x_max = c.getPoint().getX() + c.getLargeur();
//         int y_max = c.getPoint().getY() + c.getHauteur();
//         int delta_x = p.getX() + getLargeur() - x_max;
//         int delta_y = p.getY() + getHauteur() - y_max;
//         if (delta_x < 0)
//         {
//             w += delta_x;
//         }
//
//         if (delta_y < 0)
//         {
//             h += delta_y;
//         }
//     }
// }


// A finir: reprendre ici 

// void Groupe::add(Forme &f){
//     if (nb_f < TAILLE)
//     {
//         f.ordre = compteur;
//         this->formes[nb_f] = f;
//         nb_f++;
//         compteur++;

//         // On verifie les bords gauche/sup
//         Point p = this->getPoint();
//         if (f.getPoint().getX() < p.getX())
//         {
//             p.setX(f.getPoint().getX());
//         }

//         if (f.getPoint().getY() < p.getY())
//         {
//             p.setY(f.getPoint().getY());
//         }

//         // On verifie les dim:
//         int x_max = f.getPoint().getX() + f.getLargeur();
//         int y_max = f.getPoint().getY() + f.getHauteur();
//         int delta_x = p.getX() + getLargeur() - x_max;
//         int delta_y = p.getY() + getHauteur() - y_max;
//         if (delta_x < 0)
//         {
//             w += delta_x;
//         }

//         if (delta_y < 0)
//         {
//             h += delta_y;
//         }
//     }
// }