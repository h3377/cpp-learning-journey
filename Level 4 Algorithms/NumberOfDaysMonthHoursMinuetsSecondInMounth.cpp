// #5#4 Number of days-Hours-minuets-second In Month.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool IsleapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month,short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    if (Month == 2)
    {
        return IsleapYear(Month) ? 29 : 28;
    }

    short arr31Days[7] = { 1,3,5,7,8,10,12 };
    for (short i = 0; i <= 7; i++)
    {
        if (arr31Days[i - 1] == Month)
            return 31;
    }
    return 30;
    
}

short NumberOfHoursInMonth(short Month,short Year)
{
    return NumberOfDaysInMonth(Month,Year) * 24;
}

int NumberOfMinuetInMonth(short Month,short Year)
{
    return NumberOfHoursInMonth(Month,Year) * 60;
}

int NumberOfsecondInMonth(short Month,short Year)
{
    return NumberOfMinuetInMonth(Month,Year) * 60;
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
        << NumberOfDaysInMonth(Month,Year);

    cout << "\nNumber of Hours In Month [" << Month << "] Is "
        << NumberOfHoursInMonth(Month,Year);
    
    cout << "\nNumber of Minuets In Month [" << Month << "] Is "
        << NumberOfMinuetInMonth(Month,Year);

    cout << "\nNumber of Second In Month [" << Month << "] Is "
        << NumberOfDaysInMonth(Month,Year);

    system("pause>0");
    return 0;
}
