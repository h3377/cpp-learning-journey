// #4 #4Number of years-hours-days-minutes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInYears(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}
short NumberOfHoursInYears(short Year)
{
    return NumberOfDaysInYears(Year) * 24;
}
int NumberOfMinuetsInYears(short Year)
{
    return NumberOfHoursInYears(Year) * 60;
}
int NumberOfSecondInYears(short Year)
{
    return NumberOfMinuetsInYears(Year) * 60;
}
short ReadYear()
{
    short Year;
    cout << "Please enter a year to check?  ";
    cin >> Year;
    return Year;
}


int main()
{
    short Year = ReadYear();

    cout << "\nNumber of Days In Year [" << Year << "] is " 
        << NumberOfDaysInYears(Year);

    cout << "\nNumber of Hours In Year [" << Year << "] is " 
        << NumberOfHoursInYears(Year);

    cout << "\nNumber of Minuets In Year [" << Year << "] is "
        << NumberOfMinuetsInYears(Year);

    cout << "\nNumber of Days In Year [" << Year << "] is " 
        << NumberOfSecondInYears(Year);

    system("pause> 0");
    return 0;

}

