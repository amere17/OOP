#pragma once
#include "screen.h"
#include "Settings.h"
//#include "Board.h"
#include <string>
#include <vector>
//class Board;

class Guard
{
public:
	Guard(Position pos);
	Guard(int row, int col);
	void setPos(Position pos);
	void setPos(int row, int col);
	Position getPos();
	void kill();
	bool isAlive();
	void move();
	void draw(std::vector<std::string> & map);

private:
	Position m_pos;
	int m_life = 1;
};

