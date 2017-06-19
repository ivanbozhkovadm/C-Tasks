/*
--------
Task: 08|
------------------------------------------------------
		The same triangle as previous,
	but having height and symbol input by the user.
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

#include<iostream>

void drawTriangle(const int& height,const char& symbol)
{
	int numberOfSpaces;
	for(int row = 0; row < height; row++)
	{
		numberOfSpaces = height - row;
		//left side
		for(int leftElement = 0; leftElement < height; leftElement++)
		{
			(leftElement < numberOfSpaces)?(std::cout<< ' '):(std::cout<< symbol);
		}
		//right side
		for(int rightElement = 0;rightElement <= row ;rightElement++)
		{
			std::cout << symbol;
		}
		std::cout << std::endl;
	}
}

int main()
{
	int height;
	std::cout << "Please, enter height: ";
	std::cin >> height;
	char symbol;
	std::cout << "Please, enter symbol: ";
	std::cin >> symbol;

	drawTriangle(height, symbol);

	return 0;
}
