#include <fstream>
#include <iostream>
#include "catch.hpp"
#include "List.hpp"

using Cell_int = Cell_T<int>;
using List_int = List_T<int>;
using ItList_int = ItList<int>;

TEST_CASE("Cellule", "int")
{
  Cell_int c{0};

  CHECK(c.getData() == 0);
  CHECK(c.getNext() == nullptr);
  CHECK(c.getPrev() == nullptr);

  Cell_int *c2 = new Cell_int{1},
           *c1 = new Cell_int{-1};
  c.addNext(c2);
  c.addPrev(c1);

  REQUIRE(c.getNext() != nullptr);
  CHECK(c.getNext()->getData() == 1);

  REQUIRE(c.getPrev() != nullptr);
  CHECK(c.getPrev()->getData() == -1);

  delete c1;
  delete c2;
}

TEST_CASE("Liste", "int")
{
  List_int L{};

  CHECK(L.empty() == true);
  Cell_int *c = new Cell_int{0};
  Cell_int *c1 = new Cell_int{1};
  Cell_int *c2 = new Cell_int{2};
  L.push_back(c);
  L.push_back(c1);
  L.push_back(c2);

  CHECK(L.empty() == false);

  REQUIRE(L.empty() == false);

  L.display(std::cout);

  Cell_int *c4 = new Cell_int{-1};
  L.push_front(c4);

  CHECK(L.front() == c4);
  CHECK(L.back() == c2);

  CHECK(L.pop_back() == c2);
  CHECK(L.pop_front() == c4);

  CHECK(L.size() == 2);
}

TEST_CASE("Test de copie")
{

  List_int L0{};

  L0.push_back(new Cell_int{1});
  L0.push_back(new Cell_int{2});
  L0.push_back(new Cell_int{3});
  L0.push_back(new Cell_int{4});

  List_int copie{L0};
  CHECK(copie.size() == L0.size());

  L0.display(std::cout);
  std::cout << "\n";
  copie.display(std::cout);
  std::cout << "\n";
}

TEST_CASE("Test itérateur v2")
{
  List_int L{};
  
  L.push_back(new Cell_int{1});
  L.push_back(new Cell_int{2});
  L.push_back(new Cell_int{3});
  L.push_back(new Cell_int{4});


  ItList_int it = L.beginIt();

  while (it != L.end())
  {
    std::cout << *it;
    ++it;
  }
  std::cout<< std::endl;

  ItList_int it2 = L.beginIt();
  it = L.beginIt();
  CHECK(it.equals(it2));
  ++it2;
  CHECK(!it.equals(it2));
  it++;
  CHECK(it.equals(it2));

}

TEST_CASE("Fin Liste")
{
  List_int L{};
  
  L.push_back(new Cell_int{1});
  L.push_back(new Cell_int{2});
  L.push_back(new Cell_int{3});
  L.push_back(new Cell_int{4});

  CHECK(L.find(1) == L.beginIt());

  ItList_int it = L.find(1);
  L.remove(it);

  CHECK(L.find(2) == L.beginIt());

  it = L.beginIt();
  L.insert(it, 52);
  CHECK( (*(++L.beginIt())) == 52);

}