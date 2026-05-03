// #40.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;



int main()
{
    int arr[4] = { 10,20,30,40 };
    int* ptr;
    ptr= arr;

    cout << "Addresses are :\n";

    cout << ptr << endl;
    cout << ptr + 1 << endl;
    cout << ptr + 2 << endl;
    cout << ptr + 3 << endl;


    cout << "\nValues are : \n";

   /** cout << *ptr << endl;
    cout << *(ptr + 1)<< endl;
    cout << *(ptr + 2) << endl;
    cout << *(ptr + 3) << endl;*/

    for (int i = 0; i <= 3; i++)
    {
        cout << *(ptr + i) << endl;
    }

    return 0;

}

