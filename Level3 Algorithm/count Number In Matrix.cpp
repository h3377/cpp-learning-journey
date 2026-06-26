// #15 II 3 count number in matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << Matrix[i][j] << "    ";
        }
        cout << endl;
    }
   
}
short  CountNumberInMatrix(int Matrix[3][3],int Number, short Rows, short Cols)
{
    int countNumber = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number)
            {
                countNumber++;
            }
        }
      
    }
    return countNumber;

}

int main()
{
    
    int Matrix1[3][3] = { {9,1,12},{0,9,1},{0,9,9} };
    
   
     cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    int Number;
    cout << "\n Count Number in matrix?";
    cin >> Number;
    cout << "\nNumber " << Number << "count in Matrix is " << CountNumberInMatrix(Matrix1, Number, 3, 3);

    system("pause>0");
    
}


