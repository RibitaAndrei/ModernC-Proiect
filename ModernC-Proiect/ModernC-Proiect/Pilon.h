#pragma once
#include <utility>

class Pilon
{
private:
	char m_color;
	std::pair <int, int> m_position;

public:
	Pilon(char color);
	Pilon& operator=(const Pilon& copy) = default;
	Pilon(const Pilon& copy) = default;
	~Pilon() = default;

	char GetColor() const;
	void SetColor(char color);

	int GetPositionX() const;
	void SetPositionX(int posX);

	int GetPositionY() const;
	void SetPositionY(int posY);

	std::pair<int, int> GetPositionXY() const;
	void SetPositionXY(int posX, int posY);
};