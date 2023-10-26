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
};