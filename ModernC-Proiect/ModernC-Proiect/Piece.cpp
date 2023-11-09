module piece;

char pieces::Pilon::getColor() const
{
	return m_color;
}

void pieces::Pilon::setColor(char color)
{
	m_color = color;
}

int pieces::Pilon::getPositionX() const
{
	return m_position.first;
}

void pieces::Pilon::setPositionX(int posX)
{
	m_position.first = posX;
}

int pieces::Pilon::getPositionY() const
{
	return m_position.second;
}

void pieces::Pilon::setPositionY(int posY)
{
	m_position.second = posY;
}

std::pair<int, int> pieces::Pilon::getPositionXY() const
{
	return m_position;
}

void pieces::Pilon::setPositionXY(int posX, int posY)
{
	m_position.first = posX;
	m_position.second = posY;
}

pieces::Bridge::Bridge(Pilon Pilon1, Pilon Pilon2)
	:pilons{Pilon1,Pilon2}
{
}

pieces::Bridge::Bridge(const Bridge& copy)
	:pilons{copy.pilons}
{
}

pieces::Pilon pieces::Bridge::getPylon1() const
{
	return pilons.first;
}

pieces::Pilon pieces::Bridge::getPylon2() const
{
	return pilons.second;
}

void pieces::Bridge::setPylon1(Pilon pilon1)
{
	pilons.first = pilon1;
}

void pieces::Bridge::setPylon2(Pilon pilon2)
{
	pilons.second = pilon2;
}

