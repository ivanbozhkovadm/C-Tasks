/*
--------
Task: 03|
------------------------------------------------------
		Write a program that inputs three real numbers
	and outputs whether they can be sides of a triangle.
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/


#include<iostream>

bool isATriangle(const int& a,const int& b,const int& c)
{
	bool isTriangle = (a + b > c) && (a + c > b) && (b + c > a);
	return isTriangle?true:false;
}

int main()
{
	int a,
		b,
		c;
	std::cout << "Please, enter sides of the triangle: ";
	std::cin >> a >> b >> c;

	bool isTriangle = isATriangle(a,b,c);

	if(isTriangle)
	{
		std::cout << "This is a triangle!" << std::endl;
	}
	else
	{
		std::cout << "This is NOT a triangle!" << std::endl;
	}


	return 0;
}
