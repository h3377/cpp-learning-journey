// excer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<limits>

using namespace std;

void ReadNumber(vector<int>& vNumber)
{
    char response = 'Y';
    int Valu;

    while (response == 'Y'|| response == 'y')
    {
        cout << "please enter a number:";
        
        while (!(cin >> Valu))
        {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max()), "\n";

            cout << "Invaid!enter a number:";
        }

        vNumber.push_back(Valu);

        cout << "\n\ndo you want to add more elements ? Y/N";
        cin >> response;
            

    }
}
void printElements(vector<int>& vNumber)
{
    if (vNumber.empty())
    {
        cout << "No numbers to diplay.\n";
        return;
    }
    cout << "\nThe Multiplication = \n";

    for (int Number : vNumber)
    {
       
        cout << Number << " * 2 = " << Number * 2 << endl;

    }
    cout << endl;
}

int main()
{
    vector<int> vNumber;
    ReadNumber(vNumber);
    printElements(vNumber);
 
        return 0;

}
