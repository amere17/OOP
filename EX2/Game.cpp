#include "Game.h"



Game::Game()
	: gameOver(false),m_score(0), m_level(1), m_robot()
{
	m_inF.open("Board.txt");
	if (!m_inF.is_open()) {
		std::cerr << "Cannot open the Map 'Borard.txt''\n";
		exit(EXIT_FAILURE);
	}
}

void Game::run()
{
	// loading first map and it's settings
	while (loadGame() && m_robot.isAlive())
	{
		loadMap();


		while (!gameOver) {
			drawAll();
			system("CLS");
			print();
			//clearAll();
			m_robot.draw(m_map, m_bombs);
			if (m_robot.move(m_map, m_bombs)) {
				m_steps--;
				for (size_t i = 0; i < m_bombs.size(); i++)
					m_bombs[i].decTimer();
			}
			for (size_t i = 0; i < m_guards.size(); i++) {
				m_guards[i].move();
			}
			//drawAll();

			checkKills();
			if (!m_robot.isAlive() || m_steps == 0)
				gameOver = true;
			//drawAll();
			//loadMap();

			if (samePlace(m_door.getPos(), m_robot.getPos()))
				break;
		}
	}
}

bool Game::loadGame()
{
	string line;
	if (!(std::getline(m_inF, line)))
		return false;
		m_map.clear();
		std::stringstream settings(line);
		settings >> m_size;
		settings >> m_steps;
		for (int i = 0; i < m_size; i++) {
			getline(m_inF, line);
			m_map.push_back(line);
		}

		return true;
		//moveCursor({ (short)m_map.size(), 0 });
}

void Game::loadMap()
{
	for (size_t row = 0; row < m_map.size(); row++) {
		for (size_t col = 0; col < m_map.size(); col++) {
			switch (m_map[row][col])
			{
			case ROBOT:
				m_robot.setPos(row, col);
				m_map[row][col] = ' ';
				break;
			case GUARD:
			{
				Guard tempG(row, col);
				m_guards.push_back(tempG);
				m_map[row][col] = ' ';
			}
				break;
			case WALL:
			{
				Wall tempW(row, col);
				m_walls.push_back(tempW);
				m_map[row][col] = ' ';
			}
			break;
			case ROCK:
			{
				Rock tempR(row, col);
				m_rocks.push_back(tempR);
				m_map[row][col] = ' ';
			}
			break;
			case DOOR:
			{
				m_door.setPos(row, col);
				m_map[row][col] = ' ';
			}
				break;
			case BOOM:
				m_map[row][col] = ' ';
				break;
			default:
				break;
			}
		}
		m_door.hideD();
	}
}

void Game::drawAll()
{
	// draw the player
	// draw the guards
	for (size_t i = 0; i < m_guards.size(); i++)
	{
		if (m_guards[i].isAlive())
			m_guards[i].draw(m_map);
		else
			m_guards.erase(m_guards.begin() + i);
	}
	// draw the rocks
	for (size_t i = 0; i < m_rocks.size(); i++)
	{
		if(m_rocks[i].toShow())
			m_rocks[i].draw(m_map);
		else
			m_rocks.erase(m_rocks.begin() + i);
	}
	// draw the door
	m_door.draw(m_map);
	// draw the walls
	for (size_t i = 0; i < m_walls.size(); i++)
		m_walls[i].draw(m_map);


}

void Game::clearAll()
{
	m_map[m_robot.getPos().row][m_robot.getPos().col] = ' ';
	for (size_t i = 0; i < m_guards.size(); i++) {
		m_map[m_guards[i].getPos().row][m_guards[i].getPos().col] = ' ';
	}
}

void Game::print()
{
	for (int i = 0; i < m_size; i++)
		cout << m_map[i] << '\n';
	cout << "Life: " << m_robot.getLife() << '\n';
	cout << "Steps: " << m_steps << '\n';

	// draw the bombs
	for (size_t i = 0; i < m_bombs.size(); i++)
	{
		m_bombs[i].draw(m_map);
		if (m_bombs[i].boom())
			m_bombs.erase(m_bombs.begin() + i);
	}
}

void Game::checkKills()
{
	// player:
	for (size_t i = 0; i < m_guards.size(); i++) 
		if (samePlace(m_robot.getPos(), m_guards[i].getPos())) 
			m_robot.kill();

	for (size_t i = 0; i < m_bombs.size(); i++) 
		if (m_bombs[i].inRange(m_robot.getPos()) && m_bombs[i].boom())
			m_robot.kill();
	// guards:
	for (size_t i = 0; i < m_bombs.size(); i++)
		for (size_t j = 0; j < m_guards.size(); j++)
			if (m_bombs[i].inRange(m_guards[j].getPos()) && m_bombs[i].boom()) 
				m_guards[j].kill();		
	// rocks:
	for (size_t i = 0; i < m_bombs.size(); i++)
		for (size_t j = 0; j < m_rocks.size(); j++)
			if (m_bombs[i].inRange(m_rocks[j].getPos()) && m_bombs[i].boom())
			{
				m_map[m_rocks[j].getPos().row][m_rocks[j].getPos().col] = ' ';
				m_rocks.erase(m_rocks.begin() + j);
			}

	// door:
	for (size_t i = 0; i < m_bombs.size(); i++)
		if (m_bombs[i].inRange(m_door.getPos()) && m_bombs[i].boom())
			m_door.showD();
}

bool Game::validMove(Position pos)
{
	return (m_map[pos.row][pos.col] != WALL || m_map[pos.row][pos.col] != ROCK);
}

void Game::summery()
{
	system("cls");
	cout << "Level: " << m_level << "\nScore: " << m_score << '\n';
}
