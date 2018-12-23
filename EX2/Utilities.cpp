#include "Utilities.h"
/*
int manhattenDistance(const Position pos, const Position pos2)
{
	return abs(pos.col - pos2.col) + abs(pos.row - pos2.row);
}

Position shotestDist(Position robotPos, Position guardPos, Board board)
{
	Position directions[4] = { { 0,1 },{ 1,0 },{ -1,0 },{ 0,-1 } };
	Position x = guardPos;
	Position newPlace;
	int minDist = manhattenDistance(robotPos, guardPos);

	for (auto & direction : directions)
	{
		newPlace = { guardPos.col + direction.col,
							   guardPos.row + direction.row };
		if (board.inPos(newPlace) == WALL || manhattenDistance(robotPos, newPlace) == 1)
			continue;
		if (manhattenDistance(robotPos, newPlace) <= minDist)
		{
			minDist = manhattenDistance(robotPos, newPlace);
			x = newPlace;
			break;
		}
	}
	return x;
}
Position shotestNeib(Position pos, Board board)
{
	Position directions[8] =
	{ { 0,1 },{ 1,1 },{ 1,0 },{ -1,1 },{ -1,0 },{ -1,-1 },{ 0,-1 },{ 1,-1 } };

	if (board.inPos(pos) != WALL)
		return pos;

	Position mybe;
	while (1)
	{
		for (auto & direction : directions)
		{
			mybe = { pos.col + direction.col, pos.row + direction.row };

			if (isValid(mybe) && board.inPos(mybe) != WALL)
				return mybe;
		}
		if (manhattenDistance(pos, mybe) > SCREEN_HEIGHT / 2)
			break;
	}
	return mybe;
}

Position randomClosePath(Position pos, Board board)
{
	Position directions[4] = { { 0,1 },{ 1,0 },{ -1,0 },{ 0,-1 } };
	Position mybe;
	for (auto & direction : directions)
	{
		mybe = { pos.col + direction.col, pos.row + direction.row };

		if (isValid(mybe) && board.inPos(mybe) != WALL)
			return mybe;
	}
	return pos;

}

bool isValid(Position pos)
{
	return (pos.col > 0 && pos.col < SCREEN_HEIGHT)
		&& (pos.row > 0 && pos.row < SCREEN_WIDTH);
}
*/
bool samePlace(const Position pos1, const Position pos2)
{
	return (pos1.col == pos2.col &&  pos1.row == pos2.row);
}
/*
Position copyPlayer(Position pos, Position pos2, Position v3, Board board)
{
	Position mybe;

	mybe = { v3.col - (pos.col - pos2.col), v3.row - (pos.row - pos2.row) };
	if (board.inPos(mybe) == DEAMON)
		return v3;

	if (isValid(mybe) && board.inPos(mybe) != WALL)
		return mybe;

	return v3;
}
*/