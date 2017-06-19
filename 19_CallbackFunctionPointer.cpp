/*
--------
Task: 19|
------------------------------------------------------
19.	Write a program that demonstrates callback functionality using function pointers. 
	Here are the requirements/guidelines for the program:
1.	The program’s main() shall call a function isPrime that accepts two parameters: 
	an unsigned long int parameter and a function pointer parameter (see below). 
	The isPrime function shall return bool (whether the first parameter is a prime number or not).
2.	The function pointer parameter of isPrime function shall be of type that is suitable to point 
	to functions with declaration(interface):
		void callback(unsigned long, unsigned long);
3.	The program’s main() shall simply input a number, call isPrime function and then 
	display “N is prime” or “N is not prime” depending on the return value of isPrime function
4.	The callback feature is related to the second argument passed from main to the isPrime function.
	That argument shall be another function that is meant to display progress 
	(i.e. “checking divisor 73 of 127” when first argument is 73 and the second 127). 
	The function pointer shall be called from within isPrime once every iteration while checking 
	whether the number is prime or not.
5.	In that program, new display functions can be written and “injected” as the second argument to 
	isPrime functions. This keeps separation between pure calculation (isPrime) from display of 
	progress (the display functions with prototype described in 2.)
6.	Write at least 1 callback function for progress display, with the given prototype that displays 
	progress (preferably in a single line on the console) like that:
Checking divisor 2 of 11
7.	*Write a second progress display callback function, that prints progress using row chart, i.e.:
		Progress: [*******           ]
8.	Test the program with large prime numbers (i.e. 982451653) so that the user can observe the 
	progress displayed by the callback function.

------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/


#include<iostream>
#include<Windows.h>

//show or hide the input cursor
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
//move cursor position simulating clear functionality
void clearScreen()
{
	HANDLE hOut; // Get the Win32 handle representing standard output.
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// Set cursor position
	Position.X = 0;
	Position.Y = 5;
	SetConsoleCursorPosition(hOut, Position); // Move the cursor back to the top left for the next sequence of writes
}
void callback(unsigned long current, unsigned long last)
{
	ShowConsoleCursor(false);
	clearScreen();
	int coef = 50;
	int percent = (coef * current) / last;
	int visualizationPercent = (current + 2 >= last) ? 100 : (percent * 2);
	std::cout << "Checking divisor " << current << " of " << last << std::endl;
	//line
	std::cout << "          ";
	for (int i = 0; i<50; i++)
	{
		std::cout << '-';
	}
	std::cout << std::endl;
	std::cout << "Progress:[";
	char symbol = 176;
	for (int i = 0; i < coef; i++)
	{
		if (i <= percent)
			std::cout << symbol;
		else
			std::cout << ' ';
	}
	std::cout << ']' << '\t' << visualizationPercent << '%' << std::endl;
	//line
	std::cout << "          ";
	for (int i = 0; i<50; i++)
	{
		std::cout << '-';
	}
}

bool isPrime(unsigned long int number, void(*call)(unsigned long, unsigned long))
{
	bool result = true;
	for (int i = 2; i< number / 2; i++)
	{
		if (number % i == 0)
		{
			result = false;
			break;
		}
		call(i, number / 2);
	}
	return result;
}

int main()
{
	int number;
	std::cout << "(*HINT)Prime numbers: 20011,49999,100003" << std::endl;
	std::cout << "Please, enter number:";

	std::cin >> number;
	void(*fp)(unsigned long, unsigned long) = callback;
	bool checkIsPrime = isPrime(number, fp);
	std::cout << std::endl
		<< std::endl
		<< "RESULT:" << std::endl;
	if (checkIsPrime)
	{
		std::cout << number << " is PRIME" << std::endl;
	}
	else
	{
		std::cout << number << " is NOT PRIME" << std::endl;
	}
	system("pause");
	return 0;
}

