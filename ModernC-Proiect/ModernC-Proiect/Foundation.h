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

	enum class Color
	{
		None,
		Red,
		Black
	};

	bool IsOccupied();
	bool IsMined();

	void SetOccupied();
	void SetMined();

	void MakePilon(Color color);
	void MakeBridge(Color color);

	bool IsEmpty()const;
	bool IsBridge()const;
	
	PieceType GetType() const;
	void SetType(PieceType type);

	void SetColor(Color color);
	Color GetColor() const;
private:
	bool m_occupied;
	bool m_mined;
	Color m_color;
	PieceType m_piece;
};

