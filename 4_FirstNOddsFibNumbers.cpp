/*
--------
Task: 04|
------------------------------------------------------
		Write a program that calculates and outputs
  	the first N odd Fibonacci numbers, separated by
  	comma and space. N is entered from the standard
  	input.
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/


#include<iostream>
#include<vector>

void calculateOddsFibunacci(int number,std::vector<int>& oddNumbers)
{
	int firstElement = 0,
		secondElement = 1,
		next = 0;

	while(number > 0)
	{
		next = secondElement + firstElement;
		firstElement = secondElement;
		secondElement = next;
		if(next%2 == 0)
		{
			oddNumbers.push_back(next);
		}
		number--;
	}
}

void printVector(std::vector<int>& vec)
{
	int length = vec.size();

	for(int i = 0; i < length; i++)
		{
			if(i != length-1)
			{
				std::cout << vec[i]<<", ";
			}
			else
			{
				std::cout << vec[i] << std::endl;
			}
		}
}

int main()
{
	int number;
	std::cout << "Please, enter positive integer number: ";
	std::cin >> number;
	std::vector<int> oddNumbers;
	calculateOddsFibunacci(number,oddNumbers);
	std::cout << "The first "<<  number <<" odd Fibonacci numbers are:" << std::endl;
	printVector(oddNumbers);

	return 0;
}
