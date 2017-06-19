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

//NOTE: C++11 solution 
#include<iostream>
#include<regex>
#include<string>

bool isValidIBAN(const std::string& iban)
{
	std::regex iban_regex("BG[0-9]{2}[A-Z]{4}[0-9]{4}[0-9]{2}[A-Z|0-9]{8}");
	bool mach = std::regex_match(iban,iban_regex);
	return (mach) ? true : false;
}

int main()
{
	std::string iban = "BG80BNBG96611020345678";
	//std::string iban = "BG28PRCB92301021331611";
	//std::string iban = "BG69PRCB92301421331616";
	//std::string iban = "BG35UNCR70001522185617";
	
	bool check = isValidIBAN(iban);
	if (check)
	{
		std::cout << "VALID" << std::endl;
	}
	else
	{
		std::cout << "NOT valid" << std::endl;
	}

	return 0;
}
