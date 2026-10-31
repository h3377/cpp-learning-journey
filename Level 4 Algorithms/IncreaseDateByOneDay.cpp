// #16#4 Increase date by one day.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct sDate
{
	short Day;
	short Month;
	short Year;

};

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
bool IsDateLastDayInMonth(sDate Date)
{
	return ((Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year)));
}
bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}


sDate IncreaseDateByDayOne(sDate &date)
{
	
	if (IsDateLastDayInMonth(date))
	{
		if (IsLastMonthInYear(date.Month))

		{
			date.Day = 1;
			date.Month = 1;
			date.Year++;
		}
		else
		{
			date.Day = 1;
			date.Month++;
		}
	}
	else
	{
		date.Day++;

	}
return date;

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
	cout << "Enter a Month to check?";
	cin >> Month;
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "Enter a Year to check?";
	cin >> Year;
	return Year;
}
sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}
int main()
{
	sDate date = ReadFullDate();

	date = IncreaseDateByDayOne(date);

	cout << "\nDate after adding one day is :"
		<< date.Day << "/" << date.Month << "/" << date.Year;

	system("pause>0");

	return 0;
    
}
