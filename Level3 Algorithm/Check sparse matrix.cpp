// #16 II 3 Check spares matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

short CountNumberInMatrix(int Matrix1[3][3], int Number, short
    Rows, short Cols)
{
    short NumberCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                NumberCount++;
            };
        }
    }
    return NumberCount;
}

bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    short MatrixSize = Rows * Cols;
    return (CountNumberInMatrix(Matrix1, 0, 3, 3) >= ceil((float)MatrixSize / 2));
}

int main()
{
    int Matrix[3][3] = { {0,0,12},{0,0,1},{0,0,9} };
    int Matrix1[3][3] = { {12,10,3},{2,32,0},{0,2,0} };
    

    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    

    if (IsSparseMatrix(Matrix1, 3, 3))
        cout << "\nYes: Matrix is sparce\n";
    else
        cout << "\nNo:Matrix is NOT sparce\n";


    



    system("pause>0");
    
}

