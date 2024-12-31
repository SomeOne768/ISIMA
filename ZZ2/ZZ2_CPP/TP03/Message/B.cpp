#include <cstdio>
#include "B.hpp"
#include "A.hpp"

void B::send(A *a)
{
    a->exec(1);
}

void B::exec(int x)
{
    j += x;
}