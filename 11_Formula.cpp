/*
--------
Task: 11|
------------------------------------------------------
	Write a program that calculates the following:
R = p1 - 2p2 + 3p3 - 4p4… NpN
where pi is i-th prime number. N is input by the user. 
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
int calculateFormula(const int N)
{
	int result = 0;
	int arr [N];
	int testIfPrime = 1;
	int currentElement = 0;

	while(currentElement < N)
	{
		if(isPrime(testIfPrime))
		{
			arr[currentElement] =testIfPrime;
			currentElement++;
		}
		testIfPrime++;
	}

	for(int i = 1; i <= N; i++)
	{
		if(i%2==0)
		{
			result -= i*arr[i-1];
		}
		else
		{
			result += i*arr[i-1];
		}
	}
	return result;
}

int main()
{
	std::cout << '\n' <<calculateFormula(11);

	return 0;
}
