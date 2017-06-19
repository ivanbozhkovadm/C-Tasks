/*
--------
Task: 22|
------------------------------------------------------
Write a program that inputs an IBAN number			  |
and calculates whether it is a valid Bulgarian IBAN.  |
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

#include<iostream>

bool isDigit(const char& c)
{
	return (c >= '0' && c <= '9')?true:false;
}
bool isCapitalLetter(const char& c)
{
	return (c >= 'A' && c <= 'Z')?true:false;
}
bool isValidIBAN(const char* iban,int length)
{
	int iterator = 0;
	const int IBAN_LENGTH = 22;
	if(length =! IBAN_LENGTH)
	{
		return false;
	}
	//check if first two chars are letters are BG(ISO Country Code)
	if((iban[iterator] != 'B') || (iban[++iterator] != 'G'))
	{
		return false;
	}
	//chaeck if second two chars are digits(IBAN Check Digits)
	if(!(isDigit(iban[++iterator])) || !(isDigit(iban[++iterator])))
	{
		return false;
	}
	//check if next is group of four letters(Bank Identifier)
	for(int i = 0; i < 4;i++)
		{
			if(!(isCapitalLetter(iban[++iterator])))
			{
				return false;
			}
		}
	//check if next is group of four digits(Branch Identifier)
	for(int i = 0; i < 4;i++)
	{
		if(!(isDigit(iban[++iterator])))
		{
			return false;
		}
	}
	//check if next both elements are digits
	if(!(isDigit(iban[++iterator])) || !(isDigit(iban[++iterator])))
	{
		return false;
	}
	//last 8 elements must be digits or letters
	for(int i = 0; i < 8;i++)
	{
		if(!(isCapitalLetter(iban[iterator])) && (!(isDigit(iban[iterator]))))
		{
			return false;
		}
		iterator++;
	}

	return true;
}

int main()
{
	//char iban[] = "BG80BNBG96611020345678";
	//char iban[] = "BG80BNBG96611020345678";
	//char iban[] = "BG28PRCB92301021331611";
	//char iban[] = "BG69PRCB92301421331616";
	//char iban[] = "BG30UJCR0000352218M6A7";
	const int SIZE = 22;
	char iban[SIZE];
	std::cout << "Please input an IBAN: ";
	std::cin.getline(iban, SIZE);

	int length = 0;
	while(iban[length] != '\0') length++;

	bool check = isValidIBAN(iban,length);
		if (check)
		{
			std::cout << "The IBAN is valid!" << std::endl;
		}
		else
		{
			std::cout << "The IBAN is NOT valid!" << std::endl;
		}

	return 0;
}
