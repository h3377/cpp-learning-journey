// #3#4 leap year on one line code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


bool IYearLeap(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short ReadYear()
{
    short Number;
    cout << "Please enter a year to check? ";
    cin >> Number;
    return Number;
}

int main()
{
    short Year = ReadYear();

    if(IYearLeap(Year))
        cout << "Yes , Year [ " << Year << " ] is a leap Year.\n";
    else

        cout << "No , Year [ " << Year << " ] is NOT leap Year.\n";

    system("pause>0");
    return 0;
    
}

