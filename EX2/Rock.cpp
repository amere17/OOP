#include "Rock.h"

Rock::Rock(Position pos)
	:m_pos(pos), m_show(true)
{
}

Rock::Rock(int row, int col)
	: m_pos({ row,col })
{
}

Position Rock::getPos()
{
	return m_pos;
}

void Rock::hide()
{
	m_show = false;
}

bool Rock::toShow()
{
	return m_show;
}

void Rock::draw(std::vector<std::string>& map)
{
	if (m_show)
		map[m_pos.row][m_pos.col] = ROCK;
}

