#include "Bridge.h"


Bridge::Bridge(Pilon pilon1, Pilon pilon2)
    : pilons{ std::make_pair(pilon1, pilon2) }
{
}

Bridge::Bridge(const Bridge& other)
    : pilons{other.pilons}
{
}

Pilon Bridge::GetPylon1() const
{
    return pilons.first;
}

Pilon Bridge::GetPylon2() const
{
    return pilons.second;
}

void Bridge::SetPylon1(Pilon pilon1)
{
    pilons.first = pilon1;
}

void Bridge::SetPylon2(Pilon pilon2)
{
    pilons.second = pilon2;
}