#pragma once
class Player
{
private:
	char m_color; //r - red, b - black
	int m_pilonCounter, m_bridgeCounter;
public:
	Player();
	Player& operator=(const Player& copy) = default;
	Player(const Player& copy) = default;
	~Player() = default;

	char getColor();
	int getPilonCounter();
	int getBridgeCounter();

	void setColor();
	void decrementPilons();
	void decrementBridges();
};

