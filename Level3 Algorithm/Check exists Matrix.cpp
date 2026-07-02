// 17 II 3 Number Exists In Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandNumber(1, 100);

        }
    }
}
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            //printf(" %0*d ", 2, arr[i][j]);
            cout << setw(3) << arr[i][j] << "     ";
        }
        cout << "\n";
    }
}
bool ExistsMatrix(int Matrix1[3][3],int NumberToSearch, short Rows, short Cols)
{
    short numToCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
           
            if (Matrix1[i][j] == NumberToSearch)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
        

    FillMatrixWithRandomNumber(Matrix1, 3, 3);

    cout << "\nMatrix1\n";
    PrintMatrix(Matrix1, 3, 3);

    
    int Number;
    cout << "\nPlease enter the number to look for matrix?\n";
    cin >> Number;

    if (ExistsMatrix(Matrix1,Number,3, 3))
        cout << "\nYes: Matrix is Exists\n";
    else
        cout << "\nNo:Matrix is NOT Exists\n";

    system("Pause>0");
   
}
