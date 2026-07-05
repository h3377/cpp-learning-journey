

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
bool IsNumberInMatrix(int Matrix1[3][3], int NumberToSearch, short Rows, short Cols)
{
    int Number = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == NumberToSearch)
            {
                
                return true;
            }
            
           
            
        }
    }
    return false;
   
}
void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3],short Rows, short Cols)
{
    int Number;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Number = Matrix1[i][j];
            if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
            {
                cout << setw(3) << Number << " ";
            }
        }
    }
}

int main()
{
    int matrix1[3][3] = { { 77,5,16 }, { 33, 54, 1 },{22,3,1} };

    int Matrix2[3][3] = { {55,33,77},{22,1,8},{10,3,54} };

 

    cout << "\nMatrix1\n";
    PrintMatrix(matrix1, 3, 3);

    cout << "\nMatrix2\n";
    PrintMatrix(Matrix2, 3, 3);
    
    cout << "\nIntersected Number are:\n";
    PrintIntersectedNumbers(matrix1, Matrix2, 3, 3);
   
    


    system("pause>0");
}

