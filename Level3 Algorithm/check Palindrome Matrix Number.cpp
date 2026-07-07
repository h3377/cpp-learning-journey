// #20 II 3 check Palindrome Matrix Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
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
bool PalindromeMatrix(int Matrix[3][3],  short Rows, short Cols)
{
    

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols/2; j++)
        {
             
            if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
            {
                return false;
            }
            
        }
       
    }
    return true;
    
}
int main()
{
    int matrix1[3][3] = { {1,2,1},{5,5,5 },{7,3,8} };
  

    cout << "\nMatrix1\n";
    PrintMatrix(matrix1, 3, 3); 

    if (PalindromeMatrix(matrix1,3, 3))
        cout << "\nYes  : Matrix is palindrome\n";
    else
        cout << "\n NO  :Matrix is Not Palindrome\n";

    system("pause>0");

    
}

  









