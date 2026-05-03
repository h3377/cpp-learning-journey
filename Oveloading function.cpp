
#include <iostream>

using namespace std;

double Mysum(double a, double b)
{
    return (a + b);
}
int Mysum(int a, int b)
{
    return (a + b);
}
int Mysum(int a, int b, int c)
{
    return (a + b + c);
}
int Mysum(int a, int b, int c, int d)
{
    return (a + b + c + d);
}

int main()
{
    cout << Mysum(10, 20) << endl;

    return 0;
}
