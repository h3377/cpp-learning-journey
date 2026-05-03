#include <iostream>
using namespace std;

void Myfunc()
{
    static int Number = 1;

    cout << "Value of number :" << Number << "\n";

    Number++;
}

int main()
{
    Myfunc();
    Myfunc();
    Myfunc();

    return 0;
}
