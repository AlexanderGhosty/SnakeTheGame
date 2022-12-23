#include "Game.h"

Game::Game()
{
	srand(time(0));
	rand();
	MoveWindow(GetConsoleWindow(), 50, 50, 2000, 2000, true);
	score = 0;
	std::cout << "Current score: " << std::endl;
	BorderSet();
}

Game::~Game()
{
	std::cout << "Destructor work.";
}

void Game::BorderSet()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << '*';
			if (i > 0 and i != height - 1)
			{
				std::cout << std::setw(width - 1) << '*' << std::setw(0);
				break;
			}
		}
		std::cout << std::endl;
	}
}

Game::Snake::Snake()
{
	size = 1;
	dx = 1; dy = 0;
	body_posXY[0].first = 15;
	body_posXY[0].second = 10;
}

Game::Snake::~Snake()
{
}

Game::Fruit::Fruit()
{
	
}

Game::Fruit::~Fruit()
{
}

COORD Game::Fruit::DefinePosXY()
{
	return COORD();
}
