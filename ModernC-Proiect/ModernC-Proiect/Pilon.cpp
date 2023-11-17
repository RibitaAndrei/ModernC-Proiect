#include "Pilon.h"

Pilon::Pilon(char color)
    :m_color{color}
{
}

char Pilon::GetColor() const
{
    return m_color;
}

void Pilon::SetColor(char color)
{
    m_color = color;
}

int Pilon::GetPositionX() const
{
    return m_position.first;
}

void Pilon::SetPositionX(int posX)
{
    m_position.first = posX;
}

int Pilon::GetPositionY() const
{
    return m_position.second;
}

void Pilon::SetPositionY(int posY)
{
    m_position.second = posY;
}

std::pair<int, int> Pilon::GetPositionXY() const
{
    return m_position;
}

void Pilon::SetPositionXY(int posX, int posY)
{
    m_position.first = posX;
    m_position.second = posY;
}