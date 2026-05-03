#include<iostream>

using namespace std;

void PrintNumberFromMtoN(int M, int N)
{
    if (M >= N)
    {
        cout << M << endl;
        PrintNumberFromMtoN(M - 1, N);
    }
}
int main()
{
    PrintNumberFromMtoN(4, 1);

    return 0;
}
