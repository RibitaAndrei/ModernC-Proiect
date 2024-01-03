#pragma once
#include <string>
#include<vector>
#include "IPiece.h"
#include "Pilon.h"
#include "Bridge.h"
//import piece;
class Player
{
private:
	IPiece::PlayerColor m_teamColor;
	uint8_t m_pilonCounter;
	uint8_t m_bridgeCounter;
	std::string m_playerName;
	std::vector <IPiece*> m_pilons;
	std::vector <IPiece*> m_bridges;
	Player* m_nextPlayer;

public:
	Player(IPiece::PlayerColor teamColor);
	Player(std::string playerName, IPiece::PlayerColor teamColor);
	Player& operator=(const Player& copy) = default;
	Player(const Player& copy) = default;
	~Player() = default;

	IPiece::PlayerColor GetColor() const;
	int GetPilonCounter() const;
	int GetBridgeCounter() const;
	std::string GetPlayerName() const;

	void SetColor(const IPiece::PlayerColor& color);
	void SetPlayerName(const std::string& name);
	void SetBridgeCounter(const int& count);
	void SetPilonCounter(const int& count);

	void DecrementPilons();
	void DecrementBridges();

	void AddPilon(IPiece* pilon);
	void AddBridge(IPiece* firstPilon, IPiece* secondPilon, Player* activePlayer);

	IPiece* GetLastBridge() const;

	void SetNextPlayer(Player& player);
	Player* GetNextPlayer() const;
};