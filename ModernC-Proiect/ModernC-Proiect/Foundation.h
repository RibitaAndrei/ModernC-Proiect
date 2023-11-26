#pragma once
#include <utility>
class Foundation
{
public:
	using Position = std::pair<size_t, size_t>;
	enum class PlayerColor
	{
		NoColor,
		Red,
		Black
	};

	Foundation();
	Foundation(Position position);
	Foundation(Position position, PlayerColor color);
	Foundation& operator=(const Foundation& copy) = default;
	Foundation(const Foundation& copy) = default;
	virtual ~Foundation() = default;
	
	virtual Position GetPosition() const;
	virtual void SetPosition(Position& position);

	virtual size_t GetRow() const;
	virtual void SetRow(size_t& row);

	virtual size_t GetColumn() const;
	virtual void SetColumn(size_t& col);

	virtual PlayerColor GetColor() const = 0;
	virtual void SetColor(const PlayerColor& color) = 0;

	virtual PlayerColor GetColor() const = 0;
	virtual void SetColor(const PlayerColor& color) = 0;
protected:
	Position m_position;
	PlayerColor m_color;
};

