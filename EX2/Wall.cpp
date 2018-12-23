#include "Wall.h"


Wall::Wall(Position pos)
	:m_pos(pos)
{
}

Wall::Wall(int row, int col)
	: m_pos({ row,col })
{
}

void Wall::draw(std::vector<std::string> & map)
{
	map[m_pos.row][m_pos.col]= WALL;
}