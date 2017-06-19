/*
--------
Task: 07|
------------------------------------------------------
	Write a program that outputs the following triangle 
	(height = 11)
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

#include<iostream>

int main()
{
	const int height = 11;
	int numberOfSpaces;

	for(int row = 0; row < height; row++)
	{
		numberOfSpaces = height - row;
		//left side
		for(int leftElement = 0; leftElement < height; leftElement++)
		{
			(leftElement < numberOfSpaces)?(std::cout<< ' '):(std::cout<< '*');
		}
		//right side
		for(int rightElement = 0;rightElement <= row ;rightElement++)
		{
			std::cout << '*';
		}
		std::cout << std::endl;
	}
	return 0;
}
