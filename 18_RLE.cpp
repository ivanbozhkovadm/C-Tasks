/*
--------
Task: 18|
------------------------------------------------------
	Write functions encode and decode that implement Run-length Encoding on byte buffers (not strings!). 
Each of the functions shall have the following parameters:
1.	Pointer to function’s input data
2.	Length of input data (in bytes)
3.	Pointer to where function will store its output (processed) data
4.	Maximum length (limit, size) of the output buffer
Each of the functions shall return the real length of the output (processed) data.
Write also main function that demonstrates (tests) how encode and decode work. Testing idea shall be to 
take a test sequence, encode it, decode it again and compare (data and length) to the original test sequence. 
Let the main function print original, encoded and decoded data and its length for each test sequence in a way 
that makes it obvious for the user whether the program operates correctly.
Use the following test sequences:
{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 8, -56, 0, 0, 0, 0, 0, 0}
{0}
* {} (empty sequence with length 0)
{-1, -2, -3, -4, -5}
------------------------------------------------------
AUTHOR:IVAN BOZHKOV|
-------------------
*/

//NOTE: work only with binaty input(0 or 1)
#include<iostream>


int encode(char* inputData,int inputDataLength,char* outputData,int outputDataLength)
{
	int counter = 1;
	int iterator = 0;
	for(int i = 0; i < inputDataLength;i++)
	{
		if(inputData[i] != inputData[i+1])
		{
			outputData[iterator] = inputData[i];
			iterator++;
		}
		else
		{
			while(inputData[i] == inputData[i+1])
			{
				counter++;
				i++;
			}
			outputData[iterator] = (char)('0' + counter);
			iterator++;
			outputData[iterator] = inputData[i];
			iterator++;
			counter = 1;
		}
	}
	return iterator;
}
int decode(char* inputData,int inputDataLength,char* outputData,int outputDataLength)
{
	int iterator = 0;
	for(int i = 0; i < inputDataLength; i++)
	{
		if(inputData[i] == '0' || inputData[i] == '1')
		{
			outputData[iterator] = inputData[i];
			iterator++;
		}
		else
		{
			int dounCounter = inputData[i]-'0';
			char newNumber = inputData[i+1];
			while(dounCounter > 0)
			{
				outputData[iterator] = newNumber;
				iterator++;
				dounCounter--;
			}
			i++;
		}
	}
	return iterator;
}
void displayData(char* data,int length)
{
	for(int i = 0; i < length; i++)
	{
		std::cout << data[i] << ' ';
	}
}
void displayCStyleArray(char* arr)
{
	for(int i = 0; arr[i] != '\0'; i++ )
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}
int main()
{
	//input data
	char inputData[] = {"01000110100111110001"};
	std::cout << "\t...:::Input data:::... " <<std::endl;
	displayCStyleArray(inputData);
	int inputDataLength = sizeof(inputData)/sizeof(inputData[0]);
	//maximal expected output length
	int outputDataLength = inputDataLength;
	char outputData[outputDataLength]; //store encoded data
	int realOutputDataLength = encode(inputData,inputDataLength,outputData,outputDataLength);
	std::cout << "\t...:::Encoded data:::... " <<std::endl;
	displayData(outputData,realOutputDataLength);

	char decodeData[inputDataLength]; //store decoded data
	int realDecodedOutputData = decode(outputData,realOutputDataLength,decodeData,inputDataLength);
	std::cout <<std::endl <<"\t...:::Decoded data:::... " <<std::endl;
	displayData(decodeData,realDecodedOutputData);


	return 0;
}
