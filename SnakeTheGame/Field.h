#pragma once
#include <iostream>
#include <iomanip>

class Field
{
public:
	Field();
	~Field();

private:
	const int height = 30;
	const int width = 50;
	void BorderSet();
};



