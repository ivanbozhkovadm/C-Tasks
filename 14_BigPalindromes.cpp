/*
--------
Task: 14|
------------------------------------------------------
		Write a program that is capable of inputting 
	very long (i.e. 40-digit) numbers from the standard
	input and checks whether the number is a palindrome. 
	The program shall write “Palindromic” or
	“Not palindromic” to the standard output
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

#include<iostream>

bool isPalindromic(const long long int& n)
{
	long long int number = n;
	int digit = 0;
	long long int reversed = 0;
	//reverse number
	do
	{
		digit = number % 10; //last digit
		reversed = (reversed*10) + digit; //add last digit to reversed number
		number = number/10; //delete last digit
	}while( number != 0 );
	//check
	if(reversed == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	long long int number;
	std::cout << "Please, enter number: ";
	std::cin >> number;
	bool checkIsPalindromic = isPalindromic(number);
	if(checkIsPalindromic)
	{
		std::cout << "Palindromic!";
	}
	else
	{
		std::cout << "Not palindromic!";
	}


	return 0;
}
