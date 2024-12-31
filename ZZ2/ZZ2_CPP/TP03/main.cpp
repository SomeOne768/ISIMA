#include <iostream>
#include "Bavarde.hpp"
#include "Couple.hpp"
#include "Famille.hpp"
#include "Mere.hpp"
#include "Fille.hpp"

int main(int, char **)
{
  // const int TAILLE = 20;
  // Bavarde tab1[TAILLE];
  // Bavarde *tab2 = new Bavarde[TAILLE];
  // // Combien d'instances sont créées ?

  // for (int i = 0; i < TAILLE; ++i)
  // {
  //   tab1[i].afficher();
  //   tab2[i].afficher();
  // }

  // // Combien d'instances sont détruites ?
  // delete[] tab2;

  // Couple c{};
  // Couple c2{2, 3};

  // Famille f{5};

  Mere *pm = new Mere("mere_dyn");
  Fille *pf = new Fille("fille_dyn");
  Mere *pp = new Fille("fille vue comme mere");
  std::cout << pm->getName() // affiche Mere
            << pf->getName() // affiche Fille
            << pp->getName() // affiche Fille
            << std::endl;

  return 0;
}