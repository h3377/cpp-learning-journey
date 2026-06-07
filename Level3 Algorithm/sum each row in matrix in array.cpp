

#include <iostream>
#include <iomanip>
#include<string>

using namespace std;

int RandNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillMatrxWithRandomNumber(int arr[3][3], short Rows, short cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            arr[i][j] = RandNumber(1, 100);
        }
    }
}
void PrintMatrx(int arr[3][3], short Rows, short Cols)
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
void SumMatrxRowsInArry(int arr[3][3], int arrSum[3], short
    Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        arrSum[i] = GetRowSum(arr, i, Cols);
    }
}
void PrintSumRowMatrix(int arr [3], short Rows)
{
    cout << "\nThe following are the sum of each row in the marix:\n";
    for (short i = 0; i < Rows; i++)
    {
        cout << " ROW " << i + 1 << " sum =  " << arr[i] << endl;
    }

}

int main()
{

    srand((unsigned)time(NULL));
    int arr[3][3];
    int arrSum[3];

    fillMatrxWithRandomNumber(arr, 3, 3);

    cout << "\nThe following is a 3x3 random matrix:\n";
    printMatrx(arr, 3, 3);

    SumMatixRowsInArry(arr, arrSum, 3,3);

    PRINTSumRowMatrix(arrSum, 3);

    system("pause>0");
}

