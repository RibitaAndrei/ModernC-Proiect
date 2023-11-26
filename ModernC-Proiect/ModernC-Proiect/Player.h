#pragma once
#include <string>
#include<vector>
#include "Foundation.h"
#include "Pilon.h"
#include "Bridge.h"
//import piece;
class Player
{
private:
	//culoarea ramane de schimbat din char 
	//in PlayerColor(din Foundation.h)
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

	char GetColor() const;
	int GetPilonCounter() const;
	int GetBridgeCounter() const;
	std::string GetPlayerName() const;

	void SetColor(const char& color);
	void DecrementPilons();
	void DecrementBridges();
	void SetPlayerName(const std::string &name);
	void SetBridgeCounter(const int &count);
	void SetPilonCounter(const int &count);
};

