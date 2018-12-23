#include "Guard.h"

Guard::Guard(Position pos)
	:m_pos(pos), m_life(1)
{
}

Guard::Guard(int row, int col)
	: m_pos({ row,col }), m_life(1)
{
}

void Guard::setPos(Position pos)
{
	m_pos = pos;
}

void Guard::setPos(int row, int col)
{
	setPos({ row,col });
}

Position Guard::getPos()
{
	return m_pos;
}

void Guard::kill()
{
	m_life--;
}

bool Guard::isAlive()
{
	return (m_life > 0);
}

void Guard::move()
{
}

void Guard::draw(std::vector<std::string> & map)
{
	if(isAlive())
		map[m_pos.row][m_pos.col] = GUARD;	
}