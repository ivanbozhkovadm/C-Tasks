/*
--------
Task: 06|
------------------------------------------------------
		Write a program that checks and prints
	whether two rectangles overlap. The rectangles’
	sides are parallel to x and y axes. Each rectangle
	is determined by the coordinates of its upper-left
	and lower-right corner. Those coordinates need to
	be input (you may use integer numbers).
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/


#include<iostream>

struct Coordinates
{
	int x;
	int y;
};

struct Rectangle
{
	Coordinates upperLeft;
	Coordinates lowerRight;
};

bool isInRange(int a,int b,int x)
{
	if(x>= std::min(a,b) && x<=std::max(a,b))
	{
	 return true;
	}
	else
	{
	   return false;
	}
}
bool isRectanglesOverlap(Rectangle& rect1,Rectangle& rect2)
{
	//to do bool vars for every part
	bool checkUpperLeftX = isInRange(rect1.upperLeft.x,rect1.lowerRight.x,rect2.upperLeft.x);
	bool checkUpperLeftY = isInRange(rect1.upperLeft.y,rect1.lowerRight.y,rect2.upperLeft.y);
	bool checkLowerRightX = isInRange(rect1.upperLeft.x,rect1.lowerRight.x,rect2.lowerRight.x);
	bool checkLowerRightY = isInRange(rect1.upperLeft.y,rect1.lowerRight.y,rect2.lowerRight.y);
	
	if( checkUpperLeftX && checkUpperLeftY ||
	    checkLowerRightX && checkLowerRightY)
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
	Rectangle r1;
	r1.upperLeft.x = 0;
	r1.upperLeft.y = 10;
	r1.lowerRight.x = 20;
	r1.lowerRight.y = 0;

	Rectangle r2;
	r2.upperLeft.x = 1;
	r2.upperLeft.y = 9;
	r2.lowerRight.x = 19;
	r2.lowerRight.y = 2;

	if(isRectanglesOverlap(r1,r2))
	{
		std::cout << "Rectangles overlap" << std::endl;
	}
	else
	{
		std::cout << "Rectangles NOT overlap" << std::endl;
	}

	return 0;
}
