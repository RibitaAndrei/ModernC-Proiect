#pragma once
#include <utility>
#include "Foundation.h"

class Pilon : public Foundation
{
public:
	using Position = std::pair<size_t, size_t>;

	Pilon();
	Pilon(Foundation::PlayerColor color, Position position);
	Pilon& operator=(const Pilon& copy) = default;
	Pilon(const Pilon& copy) = default;
	~Pilon() = default;

	virtual Position GetPosition() const;
	virtual void SetPosition(Position& position);

	virtual size_t GetRow() const;
	virtual void SetRow(size_t& row);

	virtual size_t GetColumn() const;
	virtual void SetColumn(size_t& col);

	virtual Foundation::PlayerColor GetColor() const override;
	virtual void SetColor(const Foundation::PlayerColor& color) override;

private:
	Position m_position;
};