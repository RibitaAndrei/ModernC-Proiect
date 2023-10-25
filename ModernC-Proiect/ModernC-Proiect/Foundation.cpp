#include "Foundation.h"

Foundation::Foundation()
	:m_occupied{ false },
	m_mined{ false }
{
}

bool Foundation::isOccupied()
{
	return m_occupied;
}

bool Foundation::isMined()
{
	return m_mined;
}

void Foundation::setOccupied()
{
	m_occupied = true;
}

void Foundation::setMined()
{
	m_mined = true;
}

