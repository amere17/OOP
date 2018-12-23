#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Utilities.h"
#include "screen.h"
#include "Settings.h"
#include "Player.h"
#include "Guard.h"
#include "Bomb.h"
#include "Rock.h"
#include "Wall.h"
#include "Door.h"

using std::vector;
using std::string;
using std::cout;

using std::vector;
using std::string;

class Game
{
public:
	Game();
	void run();
	bool loadGame();
	void loadMap();
	void drawAll();
	void clearAll();
	void summery();
	void print();
	void checkKills();
	bool validMove(Position pos);

private:
	//Board m_board;
	std::ifstream m_inF;
	std::vector<std::string> m_map;

	Player m_robot;
	vector<Guard> m_guards;
	vector<Bomb> m_bombs;
	vector<Rock> m_rocks;
	vector<Wall> m_walls;
	Door m_door;
	
	int m_score;
	int m_level;
	int m_size;
	int m_steps;
	bool gameOver;
};

