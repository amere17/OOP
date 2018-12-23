#include "Bomb.h"
#include <iostream>

Bomb::Bomb(int row, int col)
	:m_pos({row,col}), m_timer(TIMER)
{
}

void Bomb::setPos(Position pos)
{
	m_pos = pos;
}

void Bomb::setPos(int row, int col)
{
	setPos({ row,col });
}

Position Bomb::getPos()
{
	return m_pos;
}

void Bomb::decTimer()
{
	m_timer--;
}

void Bomb::draw(std::vector<std::string> & map)
{
	if (m_timer > 0)
	{
		moveCursor({ m_pos.row,m_pos.col });
		std::cout <<m_timer;
	}
	else {
		if (map[m_pos.row][m_pos.col] != WALL)
		{
			moveCursor({ m_pos.row,m_pos.col });
			std::cout << BOOM;
		}
		if (map[m_pos.row+1][m_pos.col] != WALL)
		{
			moveCursor({ m_pos.row + 1,m_pos.col });
			std::cout << BOOM;
		}
		if (map[m_pos.row-1][m_pos.col] != WALL)
		{
			moveCursor({ m_pos.row - 1,m_pos.col });
			std::cout << BOOM;
		}
		if (map[m_pos.row][m_pos.col+1] != WALL)
		{
			moveCursor({ m_pos.row,m_pos.col + 1 });
			std::cout << BOOM;
		}
		if (map[m_pos.row][m_pos.col-1] != WALL)
		{
			moveCursor({ m_pos.row,m_pos.col - 1 });
			std::cout << BOOM;
		}
	}
}

bool Bomb::inRange(Position pos)
{
	return (samePlace(pos, m_pos) ||
		samePlace(pos, { m_pos.row - 1,m_pos.col }) || samePlace(pos, { m_pos.row + 1,m_pos.col }) ||
		samePlace(pos, { m_pos.row ,m_pos.col- 1 }) || samePlace(pos, { m_pos.row ,m_pos.col + 1 }));
}

bool Bomb::boom()
{
	return (m_timer == 0);
}
