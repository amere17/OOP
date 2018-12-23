#pragma once
#include "screen.h"
#include "Settings.h"
#include "Utilities.h"
//#include "Board.h"
#include <string>
#include <vector>
//class Board;

class Bomb
{
public:
	Bomb(int row, int col);
	//Bomb(Position pos);
	//Bomb(int row, int col);
	void setPos(Position pos);
	void setPos(int row, int col);
	Position getPos();
	void decTimer();
	void draw(std::vector<std::string> & map);
	bool inRange(Position pos);
	bool boom();

private:
	Position m_pos;
	int m_timer;
};

