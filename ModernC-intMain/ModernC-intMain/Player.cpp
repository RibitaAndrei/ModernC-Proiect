#include "Player.h"

Player::Player(IPiece::PlayerColor teamColor)
	:m_teamColor{ teamColor },
	m_pilonCounter{ 50 },
	m_bridgeCounter{ 50 }
{
}

Player::Player(std::string playerName, IPiece::PlayerColor teamColor)
	:m_pilonCounter{ 50 },
	m_bridgeCounter{ 50 },
	m_teamColor{ teamColor },
	m_playerName{ playerName }
{
}

IPiece::PlayerColor Player::GetColor() const
{

	return m_teamColor;
}

int Player::GetPilonCounter() const
{
	return m_pilonCounter;
}

int Player::GetBridgeCounter() const
{
	return m_bridgeCounter;
}

std::string Player::GetPlayerName() const
{
	return m_playerName;
}

void Player::SetColor(const IPiece::PlayerColor& color)
{
	m_teamColor = color;
}

void Player::DecrementPilons()
{
	m_pilonCounter--;
}

void Player::DecrementBridges()
{
	m_bridgeCounter--;
}

void Player::SetPlayerName(const std::string& name)
{
	m_playerName = name;
}

void Player::SetBridgeCounter(const int& count)
{
	m_bridgeCounter = count;
}

void Player::SetPilonCounter(const int& count)
{
	m_pilonCounter = count;
}

void Player::AddPilon(IPiece* pilon)
{
	m_pilons.push_back(pilon);
	DecrementPilons();
}

void Player::AddBridge(IPiece* firstPilon, IPiece* secondPilon, Player* activePlayer)
{
	m_bridges.push_back(new Bridge(firstPilon, secondPilon, activePlayer->GetColor()));
	DecrementBridges();
}

IPiece* Player::GetLastBridge() const
{
	if (!m_bridges.empty())
		return m_bridges[m_bridges.size() - 1];
}

void Player::SetNextPlayer(Player& player)
{
	m_nextPlayer = &player;
}

Player* Player::GetNextPlayer() const
{
	return m_nextPlayer;
}