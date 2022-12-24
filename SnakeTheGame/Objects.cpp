#include "Objects.h"



void Snake::Draw(const HANDLE h, const int height, const int width, bool &flag, const COORD posXY)
{
	SetConsoleTextAttribute(h, 10);
	if (size == 1)
	{
		SetConsoleCursorPosition(h, body_posXY[0]);
		putchar(' ');
		ChangeCoord(height, width, flag, posXY);
		SetConsoleCursorPosition(h, body_posXY[0]);
		putchar(head);
	}
	else
	{
		SetConsoleCursorPosition(h, body_posXY[size - 1]);
		putchar(' ');
		ChangeCoord(height, width, flag, posXY);
		SetConsoleCursorPosition(h, body_posXY[0]);
		putchar(head);
		SetConsoleCursorPosition(h, body_posXY[1]);
		putchar(body);
	}
}

void Snake::ChangeCoord(const int height, const int width, bool &flag, const COORD posXY)
{
	is_fruit_eated = false;
	if (body_posXY[0].X == 0 or body_posXY[0].X == width - 1 or body_posXY[0].Y == 0 or body_posXY[0].Y == height - 1)
	{
		flag = false;
	}
	else if (body_posXY[0].X == posXY.X and body_posXY[0].Y == posXY.Y)
	{
		body_posXY[0].X = posXY.X;
		body_posXY[0].Y = posXY.Y;
		size++;
		AddNewLink();
		is_fruit_eated = true;
	}
	else
	{
		for (int i = size - 1; i > 0; i--)
		{
			body_posXY[i].X = body_posXY[i - 1].X;
			body_posXY[i].Y = body_posXY[i - 1].Y;
		}
		body_posXY[0].X = body_posXY[0].X + dx;
		body_posXY[0].Y = body_posXY[0].Y + dy;

		int i = 1;
		for (; i < size; i++)
		{
			if (body_posXY[0].X == body_posXY[i].X and body_posXY[0].Y == body_posXY[i].Y)
			{
				flag = false;
				break;
			}

		}
	}
}

int Snake::AddNewLink()
{
	body_posXY[size - 1].X = body_posXY[size - 2].X;
	body_posXY[size - 1].Y = body_posXY[size - 2].Y;
	if (size == MAX_SIZE)
	{
		return 0;
	}
	else return 1;
}

Snake::Snake(const HANDLE h)
{
	size = 1;
	dx = 1; dy = 0;
	body_posXY[0].X = 25;
	body_posXY[0].Y = 14;

	SetConsoleCursorPosition(h, body_posXY[0]);
	SetConsoleTextAttribute(h, 10);
	putchar(head);
}

Snake::~Snake()
{
}

Fruit::Fruit(const int width, const int height, const COORD body_posXY)
{
	do {
		posXY.X = rand() % (width - 2) + 1;
		posXY.Y = rand() % (height - 2) + 1;
	} while (posXY.X != body_posXY.X and posXY.Y != body_posXY.Y);
}

Fruit::~Fruit()
{
}

void Fruit::DefinePosXY(const Snake &snake, const int height, const int width)
{
	int i = 0;
	do
	{
		posXY.X = rand() % (width - 2) + 1;
		posXY.Y = rand() % (height - 2) + 1;
		i = 0;
		for (; i < snake.size; i++)
		{
			if (posXY.X == snake.body_posXY[i].X and posXY.Y == snake.body_posXY[i].Y)
				break;
		}

	} while (i < snake.size);
}

void Fruit::Draw(HANDLE h)
{
	SetConsoleCursorPosition(h, posXY);
	SetConsoleTextAttribute(h, 12);
	putchar(sign);
}
