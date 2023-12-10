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

	Position GetPosition() const;
	void SetPosition(const Position& position);

	size_t GetRow() const;
	void SetRow(const size_t& row);

	size_t GetColumn() const;
	void SetColumn(const size_t& col);

	virtual Foundation::PlayerColor GetColor() const override;
	virtual void SetColor(const Foundation::PlayerColor& color) override;

private:
	Position m_position;
};