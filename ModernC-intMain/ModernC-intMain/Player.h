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
	Foundation::PlayerColor m_teamColor;
	int m_pilonCounter, m_bridgeCounter;
	std::string m_playerName;
	std::vector <Pilon> m_pilons;
	std::vector <Bridge> m_bridges;
	Player* m_nextPlayer;

public:
	Player(char teamColor);
	Player(std::string playerName, Foundation::PlayerColor teamColor);
	Player& operator=(const Player& copy) = default;
	Player(const Player& copy) = default;
	~Player() = default;

	Foundation::PlayerColor GetColor() const;
	int GetPilonCounter() const;
	int GetBridgeCounter() const;
	std::string GetPlayerName() const;

	void SetColor(const Foundation::PlayerColor& color);
	void DecrementPilons();
	void DecrementBridges();
	void SetPlayerName(const std::string& name);
	void SetBridgeCounter(const int& count);
	void SetPilonCounter(const int& count);

	void SetNextPlayer(Player& player);
	Player* GetNextPlayer();
};

