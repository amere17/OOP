#include "Door.h"

Door::Door()
{
}

void Door::setPos(int row, int col)
{
	m_pos.row = row;
	m_pos.col = col;
}

void Door::showD()
{
	m_hide = false;
}

void Door::hideD()
{
	m_hide = true;
}

void Door::draw(std::vector<std::string> & map)
{
	if (m_hide)
		map[m_pos.row][m_pos.col] = ROCK;
	else
		map[m_pos.row][m_pos.col] = DOOR;
}

Position Door::getPos()
{
	return m_pos;
}
