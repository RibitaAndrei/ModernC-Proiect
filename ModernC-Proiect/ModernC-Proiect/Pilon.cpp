#include "Pilon.h"

Pilon::Pilon()
    :Foundation()
{
}

Pilon::Pilon(Foundation::PlayerColor color, Position position)
    :Foundation(color),
	m_position{position}
{
}

Pilon::Position Pilon::GetPosition() const
{
	return m_position;
}

void Pilon::SetPosition(const Position& position)
{
	m_position = position;
}

size_t Pilon::GetRow() const
{
	return m_position.first;
}

void Pilon::SetRow(const size_t& row)
{
	m_position.first = row;
}

size_t Pilon::GetColumn() const
{
	return m_position.second;
}

void Pilon::SetColumn(const size_t& col)
{
	m_position.second = col;
}

Foundation::PlayerColor Pilon::GetColor() const
{
    return m_color;
}

void Pilon::SetColor(const Foundation::PlayerColor& color)
{
    m_color = color;
}

