#include "Pilon.h"

Pilon::Pilon()
	:IPiece()
{
}

Pilon::Pilon(IPiece::PlayerColor color, Position position)
	:IPiece(color),
	m_position{ position }
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

IPiece::PlayerColor Pilon::GetColor() const
{
	return m_color;
}

void Pilon::SetColor(const IPiece::PlayerColor& color)
{
	m_color = color;
}