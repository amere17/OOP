#include "Player.h"
#include <iostream>

Player::Player()
	:m_life(LIFE)
{
}

void Player::setPos(Position pos)
{
	m_pos = pos;
}

void Player::setPos(int row, int col)
{
	setPos({ row,col });
}

Position Player::getPos()
{
	return m_pos;
}

void Player::kill()
{
	m_life--;
}

int Player::getLife()
{
	return m_life;
}

bool Player::isAlive()
{
	return (m_life > 0);
}

bool Player::move(std::vector<std::string> map, std::vector<Bomb> & bombs)
{
	Position newPos = m_pos;
	switch (Keyboard::getch())
	{
	case 0:
	case SPECIAL_KEY:
		switch (Keyboard::getch())
		{
		case KB_UP:
			newPos.row--;
			if (validMove(newPos, map)) {
				setPos(newPos);
				return true;
			}
			return false;
			break;
		case KB_DOWN:
			newPos.row++;
			if (validMove(newPos, map)) {
				setPos(newPos);
				return true;
			}
			return false;
			break;
		case KB_LEFT:
			newPos.col--;
			if (validMove(newPos, map)) {
				setPos(newPos);
				return true;
			}
			return false;
			break;
		case KB_RIGHT:
			newPos.col++;
			if (validMove(newPos, map)) {
				setPos(newPos);
				return true;
			}
			return false;
			break;
		}		
		break;
	case KB_SPACE:
		return true;
			break;
	case KB_B:
	{
		Bomb tempB(m_pos.row, m_pos.col);
		bombs.push_back(tempB);
		return false;
		break;
	}

	default:
		return move(map, bombs);
	}

	if (validMove(newPos, map)) {
		map[m_pos.row][m_pos.col] = ' ';
		setPos(newPos);
		return true;
	}
	return false;
}

bool Player::validMove(Position pos, std::vector<std::string> map)
{
	return (map[pos.row][pos.col] != WALL && map[pos.row][pos.col] != ROCK);
}

void Player::draw(std::vector<std::string> & map, std::vector<Bomb> bombs)
{
	moveCursor(m_pos);
	if (bombs.size() > 0) {
		for (size_t i = 0; i < bombs.size(); i++)
			if (samePlace(m_pos, bombs[i].getPos()))
				std::cout << '%';
		else
				std::cout << '/';
	}
	else
		std::cout << '/';
}