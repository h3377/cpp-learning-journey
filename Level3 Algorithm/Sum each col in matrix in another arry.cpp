#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int RandNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Row, short Col)
{
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            arr[i][j] = RandNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short Row, short Col)
{
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << "\n";
    }
}

int ColSum(int arr[3][3], short Row, short ColArr)
{
    int sum = 0;
    for (short i = 0; i < Row -1; i++)
    {
        sum += arr[i][ColArr];
    }
    return sum;
}

void SumMatrixColsArray(int arr[3][3], int arrSum[3], short Row, short Col)
{
    for (short i = 0; i < Col; i++)
    {
        arrSum[i] = ColSum(arr, Row, i);
    }
}

void PrintEachColInAnotherArray(int arr[3], short Length)
{
    cout << "\nThe following are the sum of each col in the matrix:\n";
    for (short i = 0; i < Length; i++)
    {
        cout << " Col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];

    FillMatrixWithRandomNumber(arr, 3, 3);
    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    SumMatrixColsArray(arr, arrSum, 3, 3);
    PrintEachColInAnotherArray(arrSum, 3);

    system("pause>0");
    return 0;
}
