#include <cstdio>
#include "A.hpp"
#include "B.hpp"

void A::send(B *b)
{
    b->exec(1);
}

void A::exec(int x)
{
    i += x;
}