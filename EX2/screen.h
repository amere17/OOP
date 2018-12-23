#pragma once

struct Position
{
	int row;
	int col;
};

void moveCursor(const Position& pos);