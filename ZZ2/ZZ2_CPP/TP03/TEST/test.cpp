#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Producteur_Initialisation") {
  Producteur p;
  REQUIRE( p.getTravail() == 0);
}


TEST_CASE("Producteur_travail2") {
  Producteur p;
  p.produire(10, "test01.txt");
  p.produire(10, "test01.txt");
  p.produire(10, "test01.txt");
  REQUIRE( p.getTravail() == 3);
}