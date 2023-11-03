#pragma once
#include <string>
class Player
{
private:
	char m_color; //r - red, b - black
	int m_pilonCounter, m_bridgeCounter;
	std::string m_playerName;
public:
	Player(std::string playerName, char teamColor);
	Player& operator=(const Player& copy) = default;
	Player(const Player& copy) = default;
	~Player() = default;

	char getColor();
	int getPilonCounter();
	int getBridgeCounter();
	std::string GetPlayerName();

	void setColor(char color);
	void decrementPilons();
	void decrementBridges();
	void SetPlayerName(std::string name);
};

