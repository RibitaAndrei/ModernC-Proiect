#include "Player.h"

Player::Player(char teamColor)
{
}

Player::Player(std::string playerName, char teamColor)
	:m_pilonCounter{ 50 },
	m_bridgeCounter{ 50 },
	m_color{ teamColor },
	m_playerName{ playerName }
{
}

char Player::GetColor() const
{

	return m_color;
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

void Player::SetColor(const char& color)
{
	m_color = color;
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
