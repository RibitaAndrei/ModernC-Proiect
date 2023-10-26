#include "Pilon.h"

char Pilon::getColor() const
{
    return m_color;
}

void Pilon::setColor(char color)
{
    m_color = color;
}

int Pilon::getPositionX() const
{
    return m_position.first;
}

void Pilon::setPositionX(int posX)
{
    m_position.first = posX;
}

int Pilon::getPositionY() const
{
    return m_position.second;
}

void Pilon::setPositionY(int posY)
{
    m_position.second = posY;
}

std::pair<int, int> Pilon::getPositionXY() const
{
    return m_position;
}

void Pilon::setPositionXY(int posX, int posY)
{
    m_position.first = posX;
    m_position.second = posY;
}