#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Game.h"
#include <windows.h>
#include <ctime>

class Game
{
public:
	Game();
	~Game();

private:
	class Snake
	{
	public:
		static const int MAX_SIZE = 30; // ������������ �����
		int size; // ������ ����
		std::pair <int, int> body_posXY[20]; // ���������� ���� ���� X � Y
		int dx, dy; // �������� �� ��� X � Y

		char head = '+';
		char body = '#';
		
		Snake();
		~Snake();

	};
	class Fruit
	{
	public:
		COORD posXY;
		char sign = '0';

		Fruit();
		~Fruit();
		COORD DefinePosXY();

	};

	Snake snake;
	Fruit fruit;
	const int sleep_time = 200;
	const int height = 29;
	const int width = 50;
	int score;
	void BorderSet();
};



