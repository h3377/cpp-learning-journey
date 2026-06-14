

#include <iostream>
#include <string>
#include<iomanip>

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
            arr[i][j] = RandNumber(1, 10);
        }
    }
}
void MultiplyTwoMatrix(int Matrix1[3][3],int Matrix2[3][3], int ResultMatrix[3][3], short Row, short Col)
{
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            ResultMatrix[i][j] = Matrix1[i][j] * Matrix2[i][j];
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

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3],Matrix2[3][3], ResultMatrix[3][3];

    FillMatrixWithRandomNumber(Matrix1, 3, 3);
    cout << "\nMatrix1\n";
    PrintMatrix(Matrix1, 3, 3);
    FillMatrixWithRandomNumber(Matrix2, 3, 3);
    cout << "\nMatrix2\n";
    PrintMatrix(Matrix2, 3, 3);


    MultiplyTwoMatrix(Matrix1,Matrix2, ResultMatrix, 3, 3);
 
 
  
    cout << "\nResult 1\n";
    PrintMatrix(ResultMatrix, 3, 3);
    

    system("pause>0");
    
}


