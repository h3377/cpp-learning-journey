

#include <iostream>
#include <iomanip>
#include<string>

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
            arr[i][j] = RandNumber(1, 100);
        }
    }
}


void printMatrx(int arr[3][3], short Rows, short Cols)
{
 

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << "\n";
    }
    
}
int GetRowSum(int arr[3][3], short RowNumber, short Cols)
{
    int Sum = 0;
    for (short j = 0; j < Cols; j++) {
        Sum += arr[RowNumber][j];
    }
    return Sum;
}
void PrintSumMatrixEachRows(int arr[3][3], short Rows, short cols)
{
    cout << "\n The following are the sum of each row in the matrix:\n";

    for (short i = 0; i < Rows; i++)
    {
        cout << " Row " << i + 1 << " Sum = " << GetRowSum(arr, i, cols) << endl;
    }
}


int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    fillMatrxWithRandomNumber(arr, 3, 3);
    
    cout << "\nThe Following is a 3x3 random Matrix:\n";

    printMatrx(arr, 3, 3);

    PrintSumMatrixEachRows(arr, 3, 3);
    
    

    return 0;

}

