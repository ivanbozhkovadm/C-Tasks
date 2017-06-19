/*
--------
Task: 12|
------------------------------------------------------
		Write a program that prints the maximum number 
	in a hailstone sequence, given the seed N. 
	The seed is entered from the standard input. 
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/
#include<iostream>

int MaximumNumberOfHailstoneSequence(int number)
{
	int max = 0;

	while(number > 0)
	{
		//algorithm
		if(number % 2 == 0)
		{
			number = number/2;
		}
		else
		{
			number = 3*number + 1;
		}
		//check is it max
		if(max < number)
		{
			max = number;
		}
		//break if it is endless loop
		if(number == 4)
		{
			break;
		}
	}
	return max;
}

int main()
{
	int seed;
	std::cout << "Please, enter value for seed: ";
	std::cin >> seed;
	std::cout << "The maximum number in a hailstone sequence with seed " << seed <<" is: ";
	std::cout << MaximumNumberOfHailstoneSequence(seed);
	return 0;
}
