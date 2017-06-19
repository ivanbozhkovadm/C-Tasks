/*
--------
Task: 17|
------------------------------------------------------
	Write a program that measures and displays the histogram
of how many times each letter is used in a text entered by the user. 
Assume Latin input, measure statistics for the 26 Latin letters only. 
Don’t distinguish between small and capital letters! I.e. ‘a’ and ‘A’
shall be counted as the same character. Display the histogram in a row
 chart format on the console.
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

#include<iostream>
#include<string>

struct Map{
	char c;
	int repeatedTimes;
	bool isChecked;
};

void countChars(std::string str, Map* map,int mapLength)
{
	int lastElementInTheMap = 0;
	for(int i = 0; i < mapLength; i++)
	{
		char currentChar = str[i];
			if(currentChar >=65 && currentChar <= 90)
			{
				currentChar +=32;
			}
		bool isCurrentCharExistsInMap = false;
		for(int j = 0; j < mapLength; j++)
		{
			if((currentChar == map[j].c))
			{
				map[j].repeatedTimes++;
				isCurrentCharExistsInMap = true;
			}
		}
		if(isCurrentCharExistsInMap == false)
		{
			map[lastElementInTheMap].c = currentChar;
			map[lastElementInTheMap].repeatedTimes = 1;
			lastElementInTheMap++;
		}
	}
}

void displayHistogram(Map* map,int mapLength)
{
	std::cout << "...:::Histogram:::..." << std::endl;
	for(int i = 0; i < mapLength;i++)
	{

		if(map[i].c >=97 && map[i].c<=122)
		{
			std::cout << '(' << map[i].c << ')';
			for(int j = 0; j < map[i].repeatedTimes;j++)
			{
				std::cout << '*';
			}
			std::cout << std::endl;
		}
	}
}

int main()
{
	std::string str;
	std::cout << "Please, enter your text here: ";
	std::cin >> str;
	int mapLength = str.length();

	Map* map =new Map[mapLength];

	countChars(str, map, mapLength);
	displayHistogram(map, mapLength);

	delete[] map;

	return 0;
}
