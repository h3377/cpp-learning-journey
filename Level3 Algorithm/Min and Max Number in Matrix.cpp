// #19 MIN MAX NUMBER IN MATRIX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>

using namespace std;

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
int MaxMatrix(int Matrix1[3][3], short Rows, short Cols)
{
   
    int Max = Matrix1[0][0] ;
    

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] > Max)
            {
                Max = Matrix1[i][j];
            }
           
        }
       
    }
    return Max;
}
int MinMatrix(int Matrix1[3][3], short Rows, short Cols)
{
   
    int Min = Matrix1[0][0] ;


    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if(Matrix1[i][j] < Min)
            {
                Min = Matrix1[i][j];
            }
        }

    }
    return Min;

}
int main()
{
    int matrix1[3][3] = { { 77,5,16 }, { 33, 54, 3 },{22,3,2} };

    cout << "\nMatrix1\n";
    PrintMatrix(matrix1, 3, 3);

    cout << "\nMinimum Number is: ";
    cout << MinMatrix(matrix1, 3, 3)<<endl;

    cout << "\nMax Number is :";
    cout << MaxMatrix(matrix1, 3, 3)<<endl;

    system("pause>0");
  
}

