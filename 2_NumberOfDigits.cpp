/*
--------
Task: 02|
------------------------------------------------------
	Write a program that counts and outputs the number of digits in N!
	Example:
	Please input a positive integer: 5
	Number of digits in 5! is: 3
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

#include<iostream>

int calculateFactorial(int number)
{
	int product = number;
	number--;
	
	while(number > 0)
	{
		product = number * product;
		number--;
	}
	
	return product;
}

int countNumberOfDigitsInNumber(int& number)
{
	int counter = 0;
	while(number > 0)
	{
		number = number/10;
		counter++;
	}
	return counter;
}

int main()
{

	int inputNumber;
	std::cout << "Please input a positive integer: ";
	std::cin >> inputNumber;
	int factorialNumber = calculateFactorial(inputNumber);
	std::cout << "Number of digits in "<< inputNumber << "! is: ";
	std::cout << countNumberOfDigitsInNumber(factorialNumber);

	return 0;
}
