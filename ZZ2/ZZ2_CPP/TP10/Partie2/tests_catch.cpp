#include "catch.hpp"
#include "Individu.hpp"
#include "Heritage.hpp"


TEST_CASE("Conteneur") {
  Mage *mage = new Mage{"Jik"};
  Chaman *chaman = new Chaman{"Geek"};

  std::vector<Conteneur*> v{2};
  v.push_back(Conteneur(mage));
  // v.push_back(chaman);

}


