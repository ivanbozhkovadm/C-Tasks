/*
--------
Task: 13|
------------------------------------------------------
	Write a program to print the number of digits in
the Nth palindromic prime number. 
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

bool isPalindromic(const int& n)
{
	int number = n;
	int digit = 0;
	int reversed = 0;
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

int findNthPalindromicPrime(const int& number)
{
	int counter = 0;
	int nThPalindromicPrime = 0;
	int numberOfPalindromicPrimes = 0;

	//if found Palindromic and Prime are equal to number and break
	while(numberOfPalindromicPrimes <= number)
	{
		bool checkIsPrime = isPrime(counter);
		bool checkIsPalindrome = isPalindromic(counter);
		//check and count found Palindromic and Prime
		if(checkIsPrime && checkIsPalindrome)
		{
			nThPalindromicPrime = counter;
			numberOfPalindromicPrimes++;
		}
			counter++;
	}

	return nThPalindromicPrime;
}

int numberOfDigitsInNumber(int number)
{
	int digits = 0;
	while(number != 0)
	{
		number = number/10;
		digits++;
	}
	return  digits;
}


int main()
{

	int inputNumber;
	std::cout << "Please, enter number: ";
	std::cin >> inputNumber;
	std::cout <<"N-th Palindromic Prime is: "<<
				findNthPalindromicPrime(inputNumber) << std::endl;
	std::cout << "And it have: "
			  << numberOfDigitsInNumber(findNthPalindromicPrime(inputNumber))
			  << " digits!";
	return 0;
}
