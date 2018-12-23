#pragma once
#include "screen.h"
#include "Settings.h"
#include "Utilities.h"
#include "Keyboard.h"
#include "Bomb.h"
#include <string>
#include <vector>
//#include "Board.h"
//class Board;
//class Bomb;

class Player
{
public:
	Player();
	void setPos(Position pos);
	void setPos(int row, int col);
	Position getPos();
	void kill();
	int  getLife();
	bool isAlive();
	bool move(std::vector<std::string> map, std::vector<Bomb> & bombs);
	bool validMove(Position pos, std::vector<std::string> map);
	void draw(std::vector<std::string> & map, std::vector<Bomb> bombs);

private:
	Position m_pos;
	int m_life;
};

