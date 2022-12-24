#include "Header.h"
const int sleep_time = 170;
const int height = 29;
const int width = 50;
int score;
bool flag = true;

void BorderSet();
//void ScoreSet();
void IsKeyPressed(Snake& snake);

int main()
{
	srand(time(0));
	rand();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	MoveWindow(GetConsoleWindow(), 50, 50, 2000, 2000, true);
	//ScoreSet();
	BorderSet();

	CONSOLE_CURSOR_INFO cci = { sizeof(cci), false };
	SetConsoleCursorInfo(h, &cci);

	Snake snake(h);
	Fruit fruit(width, height, snake.body_posXY[0]);
	fruit.Draw(h);

	do {
		Sleep(sleep_time);
		IsKeyPressed(snake);
		snake.Draw(h, height, width, flag, fruit.posXY);
		if (snake.is_fruit_eated)
		{
			fruit.DefinePosXY(snake, height, width);
			fruit.Draw(h);
		}

	} while (flag);
	system("cls");
	std::cout << "GAME OVER\n";

	return 0;
}

void BorderSet()
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

void ScoreSet()
{
	score = 0;
	std::cout << "Current score: " << std::endl;
}

void IsKeyPressed(Snake &snake)
{
	

	if (_kbhit())
	{
		int key = _getch();
		if (key == 0 or key == 224)
		{
			key = _getch();
		}
		switch (key)
		{
		case 80: // вниз
			snake.dy = 1;
			snake.dx = 0;
			break;
		case 72: // вверх
			snake.dy = -1;
			snake.dx = 0;
			break;
		case 75: // влево
			snake.dy = 0;
			snake.dx = -1;
			break;
		case 77: // Клавиша вправо
			snake.dy = 0;
			snake.dx = 1;
			break;
		case 27: // выход
			flag = false;
			break;
		}
	}
}
