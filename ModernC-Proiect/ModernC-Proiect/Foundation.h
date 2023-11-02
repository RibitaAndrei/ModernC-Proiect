#pragma once
class Foundation
{
public:
	Foundation();
	Foundation& operator=(const Foundation& copy) = default;
	Foundation(const Foundation& copy) = default;
	~Foundation() = default;

	enum class PieceType {
		None,
		Pilon,
		Bridge
	};

	bool IsOccupied();
	bool IsMined();

	void SetOccupied();
	void SetMined();

	void MakePilon();
private:
	bool m_occupied;
	bool m_mined;
	PieceType m_piece;
};

