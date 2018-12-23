#pragma once
#include "screen.h"
#include "Settings.h"
#include <string>
#include <vector>
//#include "Board.h"
//class Board;

class Wall
{
public:
	Wall(Position pos);
	Wall(int row, int col);
	void draw(std::vector<std::string> & map);

private:
	Position m_pos;
};