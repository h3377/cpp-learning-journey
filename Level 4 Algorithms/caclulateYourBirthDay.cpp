// #18 #4 calculate your birth days.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable:4996);

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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

sDate IncreaseDateByDayOne(sDate& date)
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

int GetDiffreanceInDays(sDate Date1, sDate Date2, bool IncludeEnd = false)
{
	int Days = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByDayOne(Date1);
	}

	return IncludeEnd ? ++Days : Days;
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
sDate GetSystemDate()
{
	sDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}

int main()
{
	cout << "\nEnter Your Date Of Birth:\n";
	sDate Date1 = ReadFullDate();

	sDate Date2 = GetSystemDate();
	 
	cout << "\nYour Age is : " << 
		GetDiffreanceInDays(Date1,Date2,true)<< "Day(s)";

	system("pause>0");
	return 0;
}

