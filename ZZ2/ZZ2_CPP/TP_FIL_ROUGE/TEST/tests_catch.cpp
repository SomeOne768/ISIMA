#include <fstream>
#include <iostream>
#include "catch.hpp"
#include "Forme.hpp"
#include "Point.hpp"
#include "Cercle.hpp"
#include "Rectangle.hpp"
#include "Groupe.hpp"

int nb_instance_forme = 0;

TEST_CASE("Instanciation", "[Point]")
{
  Point p1;
  REQUIRE(p1.getX() == 0);
  REQUIRE(p1.getY() == 0);

  p1.setX(11);
  p1.setY(21);

  REQUIRE(p1.getX() == 11);
  REQUIRE(p1.getY() == 21);

  Point p2(12, 22);

  REQUIRE(p2.getX() == 12);
  REQUIRE(p2.getY() == 22);
}

TEST_CASE("Origine", "[Point]")
{
  REQUIRE(Point::ORIGINE.getX() == 0);
  REQUIRE(Point::ORIGINE.getY() == 0);
}

TEST_CASE("Instanciation1", "[Forme]")
{
  Forme f1;
  nb_instance_forme++;
  REQUIRE(f1.getPoint().getX() == 0);
  REQUIRE(f1.getPoint().getY() == 0);
  REQUIRE(f1.getCouleur() == COULEURS::BLEU);
}

TEST_CASE("Instanciation2", "[Forme]")
{
  Forme f2;
  nb_instance_forme++;
  f2.setX(15);
  f2.setY(25);
  f2.setCouleur(COULEURS::VERT);
  REQUIRE(f2.getPoint().getX() == 15);
  REQUIRE(f2.getPoint().getY() == 25);
  REQUIRE(f2.getCouleur() == COULEURS::VERT);
  REQUIRE_FALSE(f2.getCouleur() == COULEURS::BLEU);
  REQUIRE_FALSE(f2.getCouleur() == COULEURS::ROUGE);
  REQUIRE_FALSE(f2.getCouleur() == COULEURS::JAUNE);
}

TEST_CASE("Instanciation3", "[Forme]")
{
  // SI LE TEST NE MARCHE PAS, VOUS AVEZ UNE ERREUR DANS VOTRE CODE
  Forme f2(Point(10, 20), COULEURS::ROUGE);
  nb_instance_forme++;
  REQUIRE(f2.getPoint().getX() == 10);
  REQUIRE(f2.getPoint().getY() == 20);
  REQUIRE(f2.getCouleur() == COULEURS::ROUGE);
  REQUIRE_FALSE(f2.getCouleur() == COULEURS::BLEU);

  f2.getPoint().setX(15);
  f2.getPoint().setY(25);
  f2.setCouleur(COULEURS::JAUNE);
  REQUIRE(f2.getPoint().getX() == 15);
  REQUIRE(f2.getPoint().getY() == 25);
  REQUIRE(f2.getCouleur() == COULEURS::JAUNE);
  REQUIRE_FALSE(f2.getCouleur() == COULEURS::BLEU);
  REQUIRE_FALSE(f2.getCouleur() == COULEURS::ROUGE);
}

TEST_CASE("Compteur", "[Forme]")
{
  // Pour être correct, ce test doit etre le premier sur Forme
  std::cout << nb_instance_forme << '\n';
  REQUIRE(0 + nb_instance_forme == Forme::prochainId());
  Forme f1;
  REQUIRE(0 + nb_instance_forme == f1.getId());
  REQUIRE(1 + nb_instance_forme == Forme::prochainId());
  // Verification que la valeur n'est pas decrementee accidentellement.
  Forme *p = new Forme;
  REQUIRE(1 + nb_instance_forme == p->getId());
  delete p;
  REQUIRE(2 + nb_instance_forme == Forme::prochainId());
}

TEST_CASE("Cercle", "[Cercle]")
{
  int compteur = Forme::prochainId();
  Cercle c1;
  Cercle c2(0, 2, 1);

  REQUIRE(c1.toString() == "CERCLE: 0 0 0 0");
  REQUIRE(c2.toString() == "CERCLE: -1 1 1 1");

  c2.setRayon(0);
  REQUIRE(c2.getRayon() == 0);
  REQUIRE(c2.toString() == "CERCLE: -1 1 0 0");
  REQUIRE(c2.getLargeur() == 0);
  REQUIRE(c2.getHauteur() == 0);

  REQUIRE(Forme::prochainId() == (compteur + 2));
}

TEST_CASE("Polymorphisme", "[Forme]")
{
  Forme *f1 = new Cercle;
  Forme *f2 = new Rectangle;

  REQUIRE(f1->toString() == "CERCLE: 0 0 0 0");
  REQUIRE(f2->toString() == "RECTANGLE: 0 0 0 0");

  delete f1;
  delete f2;
}

TEST_CASE("Creation d'une copie", "[Forme]")
{
  Forme f1(5, 5);
  CHECK(f1.getPoint().getX() == 5);
  CHECK(f1.getPoint().getY() == 5);
  CHECK(f1.getCouleur() == COULEURS::BLEU);
  CHECK(f1.toString() == "Forme: 5 5");

  Forme *f = f1.clone(f1);
  CHECK(f->getPoint().getX() == 5);
  CHECK(f->getPoint().getY() == 5);
  CHECK(f->getCouleur() == COULEURS::BLEU);
  CHECK(f->toString() == "Forme: 5 5");

  Cercle c{0, 0, 5};
  CHECK(c.getPoint().getX() == -5);
  CHECK(c.getPoint().getY() == -5);
  CHECK(c.getCouleur() == COULEURS::BLEU);
  CHECK(c.toString() == "CERCLE: -5 -5 5 5");

  Forme *c2 = c.clone(c);
  CHECK(c2->getPoint().getX() == -5);
  CHECK(c2->getPoint().getY() == -5);
  CHECK(c2->getCouleur() == COULEURS::BLEU);
  CHECK(c2->toString() == "CERCLE: -5 -5 5 5");


  Rectangle r{0, 0, 5, 4};;
  CHECK(r.getX() == 0);
  CHECK(r.getY() == 0);
  CHECK(r.getCouleur() == COULEURS::BLEU);
  CHECK(r.toString() == "RECTANGLE: 0 0 5 4");

  Forme *r2 = r.clone(r);
  CHECK(r2->getX() == 0);
  CHECK(r2->getY() == 0);
  CHECK(r2->getCouleur() == COULEURS::BLEU);
  CHECK(r2->toString() == "RECTANGLE: 0 0 5 4");


  delete f;
  delete c2;
  delete r2;


}

TEST_CASE("Test vector", "[Group]")
{
  Groupe g;
  CHECK(g.compteur == 0);
  CHECK(g.nb_f == 0);

  Cercle c(0,0,5);// = new Cercle(0,0,5);
  g.add(c);

  CHECK(g.compteur == 1);
  CHECK(g.nb_f == 1);
}