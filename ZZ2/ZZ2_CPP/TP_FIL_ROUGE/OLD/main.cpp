#include <iostream>
#include "Rectangle.hpp"
#include "Cercle.hpp"
#include "Liste.hpp"

#include "Forme.hpp"

void afficher1(Forme f)
{
   f.afficher();
}

void afficher2(Forme &f)
{
   f.afficher();
}

void afficher3(Forme *f)
{
   f->afficher();
}

int main(int, char **)
{

   Liste L{};

   printf("%d\n", L.getCompteur());

   L.toString();

   Cercle c, c2(2, 2, 2);
   Rectangle r, r2(2, 2, 2, 2);

   L.cercles[0] = c;
   L.cercles[1] = c2;
   L.rectangles[0] = r;
   L.rectangles[0] = r2;

   L.add(c);
   L.add(r);
   L.add(r2);
   L.add(c2);
   std::cout << L.nb_c << L.nb_r << "\n";
   printf("%s\n", L.toString().c_str());

   L.afficher();

   Cercle cercle;

   std::cout << "Troncatude:\n";

   afficher1(cercle);
   afficher2(cercle);
   afficher3(&cercle);

   //std::cout << "test troncature:\n";
   // DEMANDER PROF : Liste::afficherTab(&L.cercles, L.nb_c);

   // L a 2 cercles et 2 rectangles
   L.testProf();

   return 0;
}