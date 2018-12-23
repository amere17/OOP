#pragma once
#include "screen.h"
#include "Settings.h"
#include <string>
#include <vector>
//#include "Board.h"
//class Board;

class Rock
{
public:
	Rock(Position pos);
	Rock(int row, int col);
	Position getPos();
	void hide();
	bool toShow();
	void draw(std::vector<std::string> & map);

private:
	Position m_pos;
	bool m_show;
};

