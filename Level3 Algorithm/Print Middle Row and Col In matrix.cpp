// #9 II 3  PRINT MIDILL ROW AND COL IN MATRIX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

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
			arr[i][j] = RandNumber(1, 100);
		}
	}
}
void PrintMatrix(int Arr[3][3], short Row, short Col)
{
	for (short i = 0; i < Row; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			printf("%0*d   ", 2, Arr[i][j]);
		}
		cout << "\n";
	}
}

void PrintMiddleRow(int arr[3][3], short Row,short Col)
{

	short MiddleRow =Row / 2;

	for (short j = 0; j < Row; j++)
	{
		printf("%0*d    ", 2, arr[MiddleRow][j]);
	}
	cout << "\n";
}
void PrintCol(int arr[3][3],short Row ,short Col)
{
	short MiddleCol = Col / 2;

	for (short j = 0; j < Col; j++)
	{
		printf("%0*d     ", 2, arr[j][MiddleCol]);
	}
	cout << "\n";
}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillMatrixWithRandomNumber(Matrix1, 3, 3);

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	

	cout << "\nMiddle Row Of Matrix1 is:\n";
	PrintMiddleRow(Matrix1, 3,3);

	cout << "\nMiddle Col Of Matrix1 is:\n";
	PrintCol (Matrix1, 3,3);

	system("pause>0");

	
}

