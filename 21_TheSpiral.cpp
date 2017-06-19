/*
--------
Task: 21|
------------------------------------------------------
Write a program that outputs the first N natural	  | 
numbers in a square spiral of size S 				  |
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/


#include<iostream>
#include <iomanip>

int countNumberOfDigitsInNumber(int number)
{
	int counter = 0;
	while(number > 0)
	{
		number = number/10;
		counter++;
	}
	return counter;
}

void printSpiral(int number,int size)
{
	const int ROWS = size;
	const int COLS = ROWS;
	int arr[ROWS][COLS]={0};

	int top = 0;
	int bottom = ROWS-1;
	int left = 0;
	int right = COLS-1;
	int counter = 1;

	while(top <= bottom && left <= right)
	{
	//right
		for(int i = left; (i <= right) && (counter <= number);i++)
		{
			arr[top][i] = counter++;
		}
		top++;
	//down
		for(int i = top; (i <= bottom) && (counter <= number);i++)
		{
			arr[i][right] = counter++;
		}
		right--;
	//left
		for(int i = right; (i >= left) && (counter <= number);i--)
		{
			arr[bottom][i] = counter++;
		}
		bottom--;
	//up
		for(int i = bottom; (i >= top) && (counter <= number);i--)
		{
			arr[i][left] = counter++;
		}
		left++;
	}

	//print
	int digits = countNumberOfDigitsInNumber(number)+1;
	for(int i = 0;i < ROWS;i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			std::cout << std::setw(digits) <<arr[i][j];
		}
		std::cout << std::endl;
	}
}

int main()
{
	int number = 100;
	int size = 10;
	printSpiral(number,size);

	return 0;
}
