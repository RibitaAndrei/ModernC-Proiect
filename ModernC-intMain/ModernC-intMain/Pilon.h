#pragma once
#include <utility>
#include "IPiece.h"

class Pilon : public IPiece
{
public:
	using Position = std::pair<size_t, size_t>;

	Pilon();
	Pilon(IPiece::PlayerColor color, Position position);
	Pilon& operator=(const Pilon& copy) = default;
	Pilon(const Pilon& copy) = default;
	~Pilon() = default;

	Position GetPosition() const;
	void SetPosition(const Position& position);

	size_t GetRow() const;
	void SetRow(const size_t& row);

	size_t GetColumn() const;
	void SetColumn(const size_t& col);

	virtual IPiece::PlayerColor GetColor() const override;
	virtual void SetColor(const IPiece::PlayerColor& color) override;

private:
	Position m_position;
};