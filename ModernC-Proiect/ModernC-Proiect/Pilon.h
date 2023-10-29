#pragma once
#include <utility>

class Pilon
{
private:
	char m_color;
	std::pair <int, int> m_position;

public:
	Pilon();
	Pilon& operator=(const Pilon& copy) = default;
	Pilon(const Pilon& copy) = default;
	~Pilon() = default;

	char getColor() const;
	void setColor(char color);

	int getPositionX() const;
	void setPositionX(int posX);

	int getPositionY() const;
	void setPositionY(int posY);

	std::pair<int, int> getPositionXY() const;
	void setPositionXY(int posX, int posY);
};