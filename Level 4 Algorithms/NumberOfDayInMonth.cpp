// #6#4 Number Of Date In a Month Short Logic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool IsLeap(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDataInMonth(short Month,short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month ==2) ? (IsLeap(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
short ReadYear()
{
    short Year;
    cout << "Please enter a Year to check? ";
    cin >> Year;
    return Year;
}


short ReadMonth()
{
    short Month;
    cout << "Please enter a month to check? ";
    cin >> Month;
    return Month;
}


int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumber of Days In Month [" << Month << "] Is "
        << NumberOfDataInMonth(Month, Year);

    system("pause>0");
    return 0;
}
