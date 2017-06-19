/*
--------
Task: 05|
------------------------------------------------------
		Write a program that calculates and outputs
	the total sum of the digits of the first
	N Fibonacci numbers.
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

#include<iostream>

void calculateFibunacci(int number)
{
	int first = 0,
		second = 1,
		next = number-1,
		sum = 0;

	while(number > 0)
	{
		next = first + second;
		first = second;
		second = next;

		number--;
		int digits = next;
		while(digits)
		{
			digits = digits%10;
			sum += digits;
			digits = digits/10;
		}

	}
	std::cout << "SUM: "<< sum;
}

int main()
{
	int number = 9;
	calculateFibunacci(number);


	return 0;
}
