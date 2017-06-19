/*
--------
Task: 10|
------------------------------------------------------
		Write a program that inputs an integer and checks 
	whether it is a prime number. 
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

#include<iostream>

bool isPrime(const int& number)
{
	bool result = true;
	for(int i = 2; i< number / 2; i++ )
	{
		if( number % i == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}

int main()
{
	int number;
	std::cout << "Please, enter number: ";
	std::cin >> number;
	if(isPrime(number))
	{
		std::cout << "Is prime!";
	}
	else
	{
		std::cout << "Is NOT prime!";
	}
	return 0;
}
