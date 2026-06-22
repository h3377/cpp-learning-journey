// #12 II 3 check Typical matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

int RandNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void fillMatrxWithRandomNumber(int arr[3][3], short Rows, short cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            arr[i][j] = RandNumber(1, 10);
        }
    }
}
int sumOfMatrix(int arr[3][3], short Rows, short Col)
{
    int sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Col; j++)
        {

            sum += arr[i][j];
        }

    }
    return sum;
}
bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Col)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            if (Matrix1[i][j] != Matrix2[i][j])
            {
                return false;
            }
        }
        return true;
   }
}
void printMatrix(int arr[3][3], short Rows, short Cols)
{


    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf("%0*d    ", 2, arr[i][j]);
        }
        cout << "\n";
    }

}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3],Matrix2[3][3];

    fillMatrxWithRandomNumber(Matrix, 3, 3);

    cout << "\nMatrix1:\n";
    printMatrix(Matrix, 3, 3);

    fillMatrxWithRandomNumber(Matrix2, 3, 3);
    cout << "\nMatrix2:\n";
    printMatrix(Matrix2, 3, 3);

    if(AreTypicalMatrices(Matrix, Matrix2, 3, 3)) 
        cout << "\nYES: both Matrices are Typical.";
    else
        cout << "\nNo: Matrices are NOT Typical.";

    system("pause>0");
}
