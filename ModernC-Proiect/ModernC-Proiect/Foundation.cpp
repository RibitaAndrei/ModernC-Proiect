#include "Foundation.h"

Foundation::Foundation()
	:occupied{ false },
	mined{ false }
{
}

bool Foundation::isOccupied()
{
	return occupied;
}

bool Foundation::isMined()
{
	return mined;
}

void Foundation::setOccupied()
{
	occupied = true;
}

void Foundation::setMined()
{
	mined = true;
}

