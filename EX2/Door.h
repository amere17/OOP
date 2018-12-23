#pragma once
#include "screen.h"
#include "Settings.h"
//#include "Board.h"
#include <string>
#include <vector>
//class Board;

class Door
{
public:
	Door();
	void setPos(int row, int col);
	void showD();
	void hideD();
	void draw(std::vector<std::string> & map);
	Position getPos();
	
private:
	Position m_pos;
	bool m_hide = true;
};

