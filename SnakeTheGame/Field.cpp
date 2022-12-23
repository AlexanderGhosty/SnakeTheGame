#include "Field.h"

Field::Field()
{
	std::cout << "Starting game!" << std::endl;
	BorderSet();
}

Field::~Field()
{
	std::cout << "Destructor work.";
}

void Field::BorderSet()
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