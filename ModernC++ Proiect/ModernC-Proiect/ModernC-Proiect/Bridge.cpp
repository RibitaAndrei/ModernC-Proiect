#include "Bridge.h"

Pilon Bridge::getPylon1() const
{
    return pilons.first;
}

Pilon Bridge::getPylon2() const
{
    return pilons.second;
}

void Bridge::setPylon1(Pilon pilon1)
{
    pilons.first = pilon1;
}

void Bridge::setPylon2(Pilon pilon2)
{
    pilons.second = pilon2;
}