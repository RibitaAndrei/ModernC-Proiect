#include "Player.h"

Player::Player()
{
	m_pilonCounter = 50;
	m_bridgeCounter = 50;
	m_color = 'r';

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
