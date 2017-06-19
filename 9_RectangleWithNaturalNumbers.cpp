/*
--------
Task: 09|
------------------------------------------------------
		Write a program that outputs the first N natural numbers
	in a rectangle with a given width (W). Numbers are printed
 	in ascending order sequentially in horizontal direction until
 	line is complete and the sequence continues on the next line,
 	etc. The text on the console shall look as a rectangular block
	(the last line may be incomplete). N and W are entered by the user.
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

#include<iostream>
void PrintRectangleWithNaturalNumbers1(const int& width,const int& number)
{
	int printedNumber = 0;
	int numElements = 0;

	while(printedNumber < number)
	{
		if(numElements < width)
		{
			std::cout << printedNumber << '\t';
			printedNumber++;
			numElements++;
		}
		else
		{
			numElements = 0;
			std::cout << std::endl;
		}

	}
}

int main()
{
	PrintRectangleWithNaturalNumbers1(5,22);
	return 0;
}
