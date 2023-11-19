#include "Foundation.h"

Foundation::Foundation()
	:m_occupied{ false },
	m_mined{ false },
	m_piece{PieceType::None},
	m_color{Color::None}
{
}

bool Foundation::IsOccupied()
{
	return m_occupied;
}

bool Foundation::IsMined()
{
	return m_mined;
}

void Foundation::SetOccupied()
{
	m_occupied = true;
}

void Foundation::SetMined()
{
	m_mined = true;
}

void Foundation::MakePilon(Color color)
{
	m_piece = PieceType::Pilon;
	m_color = color;
}

void Foundation::MakeBridge(Color color)
{
	m_piece = PieceType::Bridge;
	m_color = color;
}

bool Foundation::IsEmpty() const {
	//consider?m c? un obiect Foundation este gol întotdeauna
	return true;
}

bool Foundation::IsBridge() const
{
	return !IsEmpty();
}

Foundation::PieceType Foundation::GetType() const
{
	return m_piece;
}

void Foundation::SetType(PieceType type)
{
	m_piece = type;
}

void Foundation::SetColor(Color color)
{
	m_color = color;
}

Foundation::Color Foundation::GetColor() const
{
	return m_color;
}

