/*
--------
Task: 16|
------------------------------------------------------
		Write a program that makes simple quality test of the rand() library function. 
	More precisely, it shall test how uniformly the generated random numbers are distributed. 
	The guidelines for the program are the following:
1.	The well-known library function rand() shall be used in a suitable way to generate 
	N integer numbers between 0 and (M-1). M and N are entered from the standard input.
2.	M shall be in the interval [10, 50]. The program shall ask the user to re-enter M 
	if user input is not in this interval (input sanity check).
3.	N shall be in the interval [10 * M, 40 * M] in order to get good statistics with 
	good graphical appearance (see below). The user input for N shall be sanity-checked, too.
4.	During the process of generation of random numbers, statistics of the distribution should 
	be kept, counting the number of hits of each random number
5.	After all random numbers are generated and statistics measured, the result (called a histogram)
	shall be displayed on to the console in a row chart format like that (i.e. M = 15, N = 600):
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

#include<iostream>
#include <cstdlib>

struct Map{
	int value;
	int timesRepeated;
	bool checked;
};

//function check for repeatable values
//and increment counter of that element in map
void checkInMap(Map* map,int length)
{
	for(int i = 0; i < length;i++)
	{
		for(int j = 0; j < length;j++)
		{
			if((map[i].value == map[j].value) && (map[j].checked == false) ) //must be equal and not checked
			{
				map[i].timesRepeated++;
				map[j].checked = true;
			}
		}
	}
}

//Just generate random number and
//initialize variables in the map
void myRand(int n,int m,Map* map)
{
	int randNumber = 0;
	for(int i = 0; i < n;i++)
	{
		randNumber = rand() % m;
		map[i].value = randNumber;
		map[i].timesRepeated = 0;
		map[i].checked = false;
	}
}
//print map like histogram
void printMap(Map* map,int length)
{
	std::cout << std::endl <<"...:::Histogram:::..." << std::endl;
	for(int i =0; i < length; i++)
	{
		if(map[i].timesRepeated != 0)
		{
			std::cout << '(' <<map[i].value << ')';
			for(int j = 0; j < map[i].timesRepeated; j++)
			{
				std::cout << '*';
			}
			std::cout << std::endl;
		}
	}
}

//swap two elements of type Map
void swap(Map& a,Map& b)
{
	Map temp = a;
	a = b;
	b = temp;
}

int splitMap(Map* map, Map pivot,int startIndex, int endIndex)
{
	int leftBoundary = startIndex;
	int rightBoundary = endIndex;

	while (leftBoundary <rightBoundary)
		{
			while ((pivot.value < map[rightBoundary].value) && (leftBoundary < rightBoundary))
			{
				rightBoundary--;
			}
			swap(map[leftBoundary], map[rightBoundary]);

			while ((pivot.value >= map[leftBoundary].value) && (leftBoundary < rightBoundary))
			{
				leftBoundary++;
			}
			swap(map[leftBoundary], map[rightBoundary]);
		}

		return leftBoundary;
}
//Quick sort my map
void sortMap(Map* map, int startIndex, int endIndex)
{
	Map pivot = map[startIndex];
	int splitPoint;

	if(startIndex < endIndex)
	{
		splitPoint = splitMap(map, pivot, startIndex, endIndex);
		map[splitPoint] = pivot;
		sortMap(map,startIndex, splitPoint - 1);
		sortMap(map,splitPoint + 1, endIndex);
	}
}

int main()
{
	//Check interval of M
	 int m;
		do
		{
			std::cout<<"Please, enter number in range of 10 to 50: ";
			std::cin >> m;
		}while((m < 10) || (m > 50));

	//Check interval of N
	 int n;
		do
		{
			std::cout<<"Please, enter number in range of "<< 10*m <<" to "<< 40*m <<": ";
			std::cin >> n;
		}while((n < 10 * m) || (n > 40 * m));

	//Create map where collect data about
	//random numbers: value/timesRepeated/checked
	Map* map = new Map[n];

	myRand(n,m,map); //generate random numbers in the map
	checkInMap(map,n); //check for repeated numbers and calculate it

	sortMap(map,0,n); // sort with quick sort my map
	printMap(map,n);  // display histogram

	delete[] map;	// free allocated space

	 return 0;
}
