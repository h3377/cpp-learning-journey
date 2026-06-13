// #7 II 3 Traspose Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void FillMatrixWithOrderedNumber(int arr[3][3], short Row, short Col)
{

    short counter = 0;

    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            counter++;
            arr[i][j] = counter;
        }
    }
}
void PrintMatrix(int arr[3][3], short Row, short Col)
{
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            cout <<" "<< arr[i][j] << "   ";
        }
        cout << "\n";
    }
}
void TrasposeMatrix(int arr[3][3],int arrTransposed[3][3], short Row, short Col)
{
   
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {

            arrTransposed[i][j] = arr[j][i];
        }

    }
}



int main()
{
    int arr[3][3], arrTransposed[3][3];
    FillMatrixWithOrderedNumber(arr, 3, 3);
    cout << "\nThe following is a 3x3 ordered matrix:\n";
    PrintMatrix(arr, 3, 3);
    TrasposeMatrix(arr, arrTransposed, 3,3);
    cout << "\nThe following is a Transposed matrix:\n";
    PrintMatrix(arrTransposed, 3, 3);
  

    system("pause>0");
}

