#pragma once
#include <string>
#include<vector>
import piece;
class Player
{
private:
	char m_color; //r - red, b - black
	int m_pilonCounter, m_bridgeCounter;
	std::string m_playerName;
	std::vector < pieces::Pilon> m_pilons;
	std::vector < pieces::Bridge> m_bridges;

public:
	Player(char teamColor);
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
	void SetBridgeCounter(int count);
	void SetPilonCounter(int count);
};

