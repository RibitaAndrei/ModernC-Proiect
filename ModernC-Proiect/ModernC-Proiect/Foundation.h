#pragma once
class Foundation
{
private:
	bool occupied;
	bool mined;
public:
	Foundation();
	Foundation& operator=(const Foundation& copy) = default;
	Foundation(const Foundation& copy) = default;
	~Foundation() = default;

	bool isOccupied();
	bool isMined();

	void setOccupied();
	void setMined();
};

