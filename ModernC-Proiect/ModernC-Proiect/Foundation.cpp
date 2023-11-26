#include "Foundation.h"

Foundation::Foundation()
	:m_position{ std::make_pair(-1, -1) },
	m_color{ PlayerColor::NoColor }
{
}

Foundation::Foundation(Position position)
	:m_position{ position }
{
}


Foundation::Foundation(Position position, PlayerColor color)
	:m_position{ position },
	m_color{ color }
{
}

Foundation::Position Foundation::GetPosition() const
{
	return m_position;
}

void Foundation::SetPosition(Foundation::Position& position)
{
	m_position = position;
}

size_t Foundation::GetRow() const
{
	return m_position.first;
}

void Foundation::SetRow(size_t& row)
{
	m_position.first = row;
}

size_t Foundation::GetColumn() const
{
	return m_position.second;
}

void Foundation::SetColumn(size_t& col)
{
	m_position.second = col;
}
