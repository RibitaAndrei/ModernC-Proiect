#include "Bridge.h"


Bridge::Bridge(Bridge::Pilons pilons, Foundation::PlayerColor color)
	: m_pilons{ pilons },
	Foundation(color)
{
}

Bridge::Bridge(const Bridge& other)
	: m_pilons{ other.m_pilons }
{
}

Foundation* Bridge::GetFirstPilon() const
{
	return m_pilons.first;
}

Foundation* Bridge::GetSecondPilon() const
{
	return m_pilons.second;
}

void Bridge::SetFirstPilon(Pilon* pilon)
{
	m_pilons.first = pilon;
}

void Bridge::SetSecondPilon(Pilon* pilon)
{
	m_pilons.second = pilon;
}

Foundation::PlayerColor Bridge::GetColor() const
{
	return m_color;
}

void Bridge::SetColor(const Foundation::PlayerColor& color)
{
	m_color = color;
}