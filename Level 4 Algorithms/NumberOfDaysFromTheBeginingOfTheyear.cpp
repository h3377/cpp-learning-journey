// #10 #4 Days from the beginning of the year.cpp: This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool isLeapYear(short Year)
{
	// if year is divisible by 4 AND not divisible by 100
	// OR if year is divisible by 400
	// then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 ==
		0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
		days[Month - 1];
}


short TotalDaysFromTheBeginningOfYear(short Days,short Month, short Year)
{
	short totalDay = 0;

	for (int i = 1; i <= Month -1; i++)
	{
		totalDay += NumberOfDaysInAMonth(i, Year);
		
	}
	totalDay += Days;

	return totalDay;
}

short ReadDay()
{
	short Day;
	cout << "\nEnter a Day to check?";
	cin >> Day;
	return Day;
}
short ReadMonth()
{
	short Month;
	cout << "\nEnter a Month to check?";
	cin >> Month;
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "\nEnter a Year to check?";
	cin >> Year;
	return Year;
}

int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();

	cout<< "\nNumber of days from the beginning of the year is:"
	<< TotalDaysFromTheBeginningOfYear(Day,Month, Year);

	return 0;
	system("pause>0");
}
