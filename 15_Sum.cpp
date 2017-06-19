/*
--------
Task: 15|
------------------------------------------------------
		Write a program that calculates the sum of the 
	first N Mersenne primes and prints it to the 
	standard output. N is input by the user. 
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

#include<iostream>


bool isPrime(const int& number)
{
	bool result = true;
	for(int i = 2; i<= number / 2; i++ )
	{
		if( number % i == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}


//numbers that are power of two in binary are sort of 0001 0000
//if I shift right at the end result it will be 0000 0001
//if there are other ones like 0000 1001 it is not power of two
//use unsigned because we will check only positive numbers
int isPowerOfTwo (unsigned int x)
{
	while (((x & 1) == 0) && x > 1) // While x is even and > 1
	{
		x >>= 1; //right shift
	}
 return (x == 1);
}

bool isMarsennePrime(int number)
{
	bool checkIsPrime = isPrime(number);
	if(checkIsPrime)
	{
		bool checkIsPowerOfTwo = isPowerOfTwo(number+1);
		if(checkIsPowerOfTwo)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int inputNumber;
	std::cout << "Please, enter number: ";
	std::cin >> inputNumber;

	if(isMarsennePrime(inputNumber))
	{
		std::cout << inputNumber << " is Marsenne Prime!";
	}
	else
	{
		std::cout << inputNumber << " is NOT Marsenne Prime!";
	}
	return 0;
}
