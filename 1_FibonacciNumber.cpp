/*
--------
Task: 01|
------------------------------------------------------
		Write a program that inputs a positive integer N
	and outputs the Fibonacci number F2N
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

#include<iostream>


int calculateFibunacciNumber(const int& number)
{
	int firstNumber = 0,
		secondNumber = 1,
		nextNumber = number - 1;

	for(int i = 2;i<=number;i++)
	{
		nextNumber = secondNumber + firstNumber;
		firstNumber = secondNumber;
		secondNumber = nextNumber;
	}

	return nextNumber;
}

int main()
{

	int inputNumber;
	std::cout << "Please, enter positive integer number: ";
	std::cin>> inputNumber;
	std::cout << "The " <<inputNumber <<"-th Fibunacci number is: ";
	std::cout << calculateFibunacciNumber(inputNumber);


	return 0;
}
