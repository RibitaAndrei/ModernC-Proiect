#include "Player.h"

Player::Player(char teamColor)
	:m_color{teamColor}
{
}

Player::Player(std::string playerName, char teamColor)
	:m_pilonCounter{50},
	m_bridgeCounter{50},
	m_color{teamColor},
	m_playerName{playerName}
{
}

char Player::getColor()
{

	return m_color;
}

int Player::getPilonCounter()
{
	return m_pilonCounter;
}

int Player::getBridgeCounter()
{
	return m_bridgeCounter;
}

std::string Player::GetPlayerName()
{
	return m_playerName;
}

void Player::setColor(char color)
{
	m_color = color;
}

void Player::decrementPilons()
{
	m_pilonCounter--;
}

void Player::decrementBridges()
{
	m_bridgeCounter--;
}

void Player::SetPlayerName(std::string name)
{
	m_playerName = name;
}

void Player::SetBridgeCounter(int count)
{
	m_bridgeCounter = count;
}

void Player::SetPilonCounter(int count)
{
	m_pilonCounter = count;
}
