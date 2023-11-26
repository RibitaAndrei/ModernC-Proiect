#include "Pilon.h"

Pilon::Pilon()
    :Foundation()
{
}

Pilon::Pilon(Foundation::PlayerColor color, Foundation::Position position)
    :Foundation(position, color)
{
}

Foundation::PlayerColor Pilon::GetColor() const
{
    return m_color;
}

void Pilon::SetColor(const Foundation::PlayerColor& color)
{
    m_color = color;
}

