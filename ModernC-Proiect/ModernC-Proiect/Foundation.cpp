#include "Foundation.h"

Foundation::Foundation()
	:m_occupied{ false },
	m_mined{ false },
	m_piece{PieceType::None}
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

void Foundation::MakePilon()
{
	m_piece = PieceType::Pilon;
}

void Foundation::MakeBridge()
{
	m_piece = PieceType::Bridge;
}

bool Foundation::IsEmpty() const {
	//consider?m c? un obiect Foundation este gol întotdeauna
	return true;
}

