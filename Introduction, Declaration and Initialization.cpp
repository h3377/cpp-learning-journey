#include <iostream>
#include <vector>


using namespace std;

int main()
{
    vector <int> vNumber = { 10,20,30,40,50,60,70,80,90,100 };

    cout << "Number of Vector = ";

    for (int &Number : vNumber)
    {
        cout << Number << " ";

    }
    cout << endl;

    return 0;
}   
