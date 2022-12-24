#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

	class Snake
	{
	public:
		static const int MAX_SIZE = 30; // ������������ �����
		int size; // ������ ����
		COORD body_posXY[20]; // ���������� ���� ���� X � Y
		int dx, dy; // �������� �� ��� X � Y
		bool is_fruit_eated = false;

		char head = '+';
		char body = '#';
		
		void Draw(const HANDLE h, const int height, const int width, bool &flag, const COORD posXY);
		void ChangeCoord(const int height, const int width, bool &flag, const COORD posXY);
		int AddNewLink();

		Snake(HANDLE h);
		~Snake();

	};
	class Fruit
	{
	public:
		COORD posXY;
		char sign = '0';

		Fruit(const int width, const int height, const COORD body_posXY);
		~Fruit();

		void DefinePosXY(const Snake& snake, const int height, const int width);
		void Draw(const HANDLE h);
	};