// #10 II 3 Sum of Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>

using namespace std;

int RandNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}
void FillMatrixWithRandomNumber(int arr[3][3], short Row, short Col)
{
	for (short i = 0; i < Row; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			arr[i][j] = RandNumber(1, 10);
		}
	}
}
int GetMatrix1Sum(int arr[3][3], short RowNumber, short ColsNumber)
{
	int Sum = 0;
	for (short j = 0; j < ColsNumber; j++)
	{
		for (int i = 0; i < RowNumber; i++)
		{


			Sum += arr[i][j];
			
		
		}
	}
		
	

	return Sum;
}

void PrintMatrix(int arr[3][3], short Row, short Col)
{
	for (short i = 0; i < Row; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			printf("%0*d    ", 2, arr[i][j]);
		}
		cout << "\n";
	}
}
int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	

	FillMatrixWithRandomNumber(arr, 3, 3);

	cout << "\nMatrix1:\n";

	PrintMatrix(arr, 3, 3);

	cout << "\nSum Matrix1 is:\n" << GetMatrix1Sum(arr, 3, 3) << endl;



	system("pause>0");
  
}
