// #29 Hw Add elements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void ReadNumber(vector<int>& vNumber)
{
    char ReadMore = 'Y';
    int Number;

    while (ReadMore == 'Y' || ReadMore == 'y') 
    {
        cout << "please enter a number?";
        cin >> Number;

        vNumber.push_back(Number);

        cout << "\nDo you want to add more? Y/N";
        cin >> ReadMore;;
    }
}

void printVectorOfNumber(vector<int> &vNumber)
{
    cout << "Vector of Number =\n\n";

    for (int Number : vNumber)
    {
        cout << Number << endl;
    }
    cout << endl;

}

int main()
{
    vector<int> vNumber;
    ReadNumber(vNumber);
    printVectorOfNumber(vNumber);

    return 0;
}


