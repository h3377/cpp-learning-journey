// #29 Vectors Add Elements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<vector>
#include <iostream>

using namespace std;



int main()
{
    vector <int> Vnumbers;

    Vnumbers.push_back(10);
    Vnumbers.push_back(20);
    Vnumbers.push_back(30);
    Vnumbers.push_back(40);
    Vnumbers.push_back(50);
    Vnumbers.push_back(60);

    cout << "Number Elements = \n \n";

    for (int& Number : Vnumbers)
    {
        cout << Number << endl;
    }
    cout << endl;

    return 0;
}

