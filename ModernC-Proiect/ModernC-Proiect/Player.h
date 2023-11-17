#pragma once
#include <string>
#include<vector>
#include "Pilon.h"
#include "Bridge.h"
//import piece;
class Player
{
private:
	char m_color; //r - red, b - black
	int m_pilonCounter, m_bridgeCounter;
	std::string m_playerName;
	std::vector <Pilon> m_pilons;
	std::vector <Bridge> m_bridges;

public:
	Player(char teamColor);
	Player(std::string playerName, char teamColor);
	Player& operator=(const Player& copy) = default;
	Player(const Player& copy) = default;
	~Player() = default;

	char GetColor();
	int GetPilonCounter();
	int GetBridgeCounter();
	std::string GetPlayerName();

	void SetColor(char color);
	void DecrementPilons();
	void DecrementBridges();
	void SetPlayerName(std::string name);
	void SetBridgeCounter(int count);
	void SetPilonCounter(int count);
};

