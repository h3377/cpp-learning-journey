// #Check scalar Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            //printf(" %0*d ", 2, arr[i][j]);
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
bool IsScalarMarix(int Matrix1[3][3], short Rows, short Cols)
{
    int FirstDiagElemement = Matrix1[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            //check for diagonals element
            if (i == j && Matrix1[i][j] != FirstDiagElemement)
            {
                return false;
            }
            //check for rest elements
            else if (i != j && Matrix1[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int Matrix[3][3] = { {9,0,0},{0,9,0},{0,0,9} };

    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix, 3, 3);

    if (IsScalarMarix(Matrix, 3, 3))
        cout << "\nYes: Matrix is scalar\n";
    else
        cout << "\nNo:Matrix is NOT scalar\n";

    system("pause>0");
}

